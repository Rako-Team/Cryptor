
__version__ = '3.0'

import argparse
import os
import datetime
import shutil
import random
import string
import base64
import pefile

import aplib
import aplib2
import rc4

args = None

def build_pragma(image_base):
    image_base_str = hex(image_base).rstrip('L')
    header = '\n'
    header += '#pragma comment(linker, "/BASE:{}")\n'.format(image_base_str)
    return header

def build_data(pe_data, pe_data_len, loader2_data, key, overlay=None):
    part = len(pe_data) // 3
    split = random.randint(part, len(pe_data) - part)
    data1 = pe_data[:split]
    data2 = pe_data[split:]

    data1_c = ','.join(hex(ord(c)) for c in data1)
    data2_c = ','.join(hex(ord(c)) for c in data2)
    loader2_data_c = ','.join(hex(ord(c)) for c in loader2_data)
    key_c = ','.join(hex(ord(c)) for c in key)
    if overlay:
        overlay_c = ','.join(hex(ord(c)) for c in overlay)

    code = '\n'
    code += '#pragma data_seg(".rdata")\n'
    code += 'char pe_data_1[{}] = {{{}}};\n'.format(len(data1), data1_c)
    code += '#pragma data_seg(".text")\n'
    code += 'char pe_data_2[{}] = {{{}}};\n'.format(len(data2), data2_c)
    code += '#pragma data_seg(".text")\n'
    code += 'char dc2_code[{}] = {{{}}};\n'.format(len(loader2_data), loader2_data_c)
    code += 'char decryption_key[{}] = {{{}}};\n'.format(len(key), key_c)
    if overlay:
        code += 'char overlay[] = {{{}}};\n'.format(overlay_c)
    code += '#pragma data_seg()\n'

    header = '\n'
    header += '#define DATA_IS_RESOURCE {}\n'.format(int(args['data_resource']))
    header += '#define DATA_IS_BASE64 {}\n'.format(int(args['data_base64']))
    header += '#define DATA_IS_PACKED {}\n'.format(int(args['data_compress']))
    header += '#define DEPACKED_DATA_LEN {}\n'.format(pe_data_len)
    header += 'extern char pe_data_1[{}];\n'.format(len(data1))
    header += 'extern char pe_data_2[{}];\n'.format(len(data2))
    header += 'extern char dc2_code[{}];\n'.format(len(loader2_data))
    header += 'extern char decryption_key[{}];\n'.format(len(key))

    return (code, header)

def encrypt_loader2_data(data, key):
    encrypted = []
    for i, c in enumerate(data):
        encrypted.append(chr(ord(data[i]) ^ ord(key[i % len(key)])))
    return ''.join(encrypted)

def encrypt_pe_data(data, key):
    encrypted = data
    if args['data_compress']:
        #encrypted = aplib.aplib_compress(encrypted).do()
        encrypted = aplib2.pack(encrypted)
    encrypted = rc4.rc4(encrypted, key)
    if args['data_base64']:
        encrypted = base64.b64encode(encrypted)
    return encrypted

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-c', '--data-compress', action='store_true')
    parser.add_argument('-b', '--data-base64', action='store_true')
    parser.add_argument('-r', '--data-resource', action='store_true')
    parser.add_argument('-l', '--loader1-dir', default='loader1')
    parser.add_argument('-L', '--loader2-dir', default='loader2')
    parser.add_argument('-p', '--process-dir', default='process')
    parser.add_argument('input-file')
    parser.add_argument('output-file')
    return vars(parser.parse_args())

def main():
    global args
    args = parse_args()
    pe = pefile.PE(args['input-file'])
    x64 = pe.FILE_HEADER.Machine == pefile.MACHINE_TYPE['IMAGE_FILE_MACHINE_AMD64']

    timestr = datetime.datetime.now().strftime("%Y.%m.%d-%H.%M.%S.%f")
    process_dir = os.path.join(args['process_dir'], timestr)
    shutil.copytree(args['loader1_dir'], process_dir)

    chars = string.ascii_letters + string.digits
    key = ''.join(random.choice(chars) for _ in range(32))

    with open(args['input-file'], 'rb') as f:
        pe_data = f.read()
        pe_data_len = len(pe_data)
        pe_data = encrypt_pe_data(pe_data, key)

    loader2_bin = 'x64.bin' if x64 else 'x86.bin'
    with open(os.path.join(args['loader2_dir'], loader2_bin), 'rb') as f:
        loader2_data = encrypt_loader2_data(f.read(), key)

    cwd = os.getcwd()
    os.chdir(process_dir)

    data_code, data_header = build_data(pe_data, pe_data_len, loader2_data, key,
                                        pe.get_overlay())
    with open('data.c', 'a') as f:
        f.write(data_code)
    with open('data.h', 'a') as f:
        f.write(data_header)

    pragma_header = build_pragma(pe.OPTIONAL_HEADER.ImageBase)
    with open('pragma.h', 'a') as f:
        f.write(pragma_header)

    compile_bat = 'compile_x64.bat' if x64 else 'compile_x86.bat'
    os.system(compile_bat)
    os.chdir(cwd)

    crypted_exe = os.path.join(process_dir, 'loader1.exe')
    shutil.copyfile(crypted_exe, args['output-file'])

if __name__ == '__main__':
    main()
