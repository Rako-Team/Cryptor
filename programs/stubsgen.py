
import argparse
import os
import datetime
import shutil

from trash import trashcode, trashimport

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--patterns-dir', default='')
    parser.add_argument('-a', '--patterns-libs-max', type=int)
    parser.add_argument('-A', '--patterns-funcs-max', type=int)
    parser.add_argument('-i', '--static-import-dir', default='')
    parser.add_argument('-b', '--static-funcs-max', type=int)
    parser.add_argument('-I', '--dynamic-import-dir', default='')
    parser.add_argument('-c', '--dynamic-libs-max', type=int)
    parser.add_argument('-C', '--dynamic-funcs-max', type=int)
    parser.add_argument('-s', '--stubs-num', type=int, default=1)
    parser.add_argument('-r', '--rounds-num', type=int, default=0)

    parser.add_argument('input-dir')
    parser.add_argument('output-dir')
    return vars(parser.parse_args())

def main():
    args = parse_args()
    for i in range(args['stubs_num']):
        timestr = datetime.datetime.now().strftime("%Y.%m.%d-%H.%M.%S.%f")
        dist = os.path.join(args['output-dir'], timestr)
        shutil.copytree(args['input-dir'], dist)

        if args['patterns_dir']:
            loader1_c = os.path.join(dist, 'loader1.c')
            trashcode(loader1_c, args['patterns_dir'], args['rounds_num'],
                      args['patterns_libs_max'], args['patterns_funcs_max'])

        import_h = os.path.join(dist, 'import.h')
        if args['static_import_dir']:
            trashimport(import_h, args['static_import_dir'], 'static',
                        None, args['static_funcs_max'])
        if args['dynamic_import_dir']:
            trashimport(import_h, args['dynamic_import_dir'], 'dynamic',
                        args['dynamic_libs_max'], args['dynamic_funcs_max'])

if __name__ == '__main__':
    main()
