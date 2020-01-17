
import os
import random
import string

from pycparser import c_parser, c_ast, c_generator
from shutil import copyfile

TEST_PATTERNS = 'patterns'
TEST_TARGET = 'tests\\loader1.c'
TEST_ROUNDS = 5

TEST_IMPORT = 'import'
TEST_TARGET2 = 'tests\\import.h'

class OperationsGenerator(object):
    """
    ~x == x
	(-x & 1) != (x & 1)
	(-x ^ x) & 1
	x + x & 1
	x * 2^n & [0, 2^n - 1]
	!(x << 1 ^ ([0, n] | 1))
    """
    _operators = ('*', '+', '-', '&', '^', '|',  '==', '!=')
    _zero_ops = ('(~{x}=={x})', '((-{x}&1)!=({x}&1))', '((-{x}^{x})&1)',
                 '({x}+{x}&1)')
    _value_ops = ('({x}+{y})', '({x}|{y})', '(({x}+1)*{y})')
    _chars = string.ascii_letters + string.digits

    def __init__(self):
        self._parser = c_parser.CParser()

    def gen_rand_value(self, var, min, max, seed=None):
        value = random.randint(min, max)
        if seed:
            random_ops = self._random(seed, random.randint(10, 20))
            zero_ops = self._value(var, value)
            ops = '{0}={1};{0}={2}'.format(var, random_ops, zero_ops)
        else:
            ops = '{0}={1}'.format(var, value)
        return self._parser.parse('void value(){{{};}}'.format(ops)).ext[0].body

    def gen_rand_str(self, var, min, max, seed=None):
        length = random.randint(min, max)
        rstr = ''.join(random.choice(self._chars) for _ in range(length))
        ops = '{}="{}"'.format(var, rstr)
        return self._parser.parse('void str(){{{};}}'.format(ops)).ext[0].body

    def _random(self, seed, num):
        ops = seed
        const = False
        for i in range(num):
            if not const:
                operand = random.choice((seed, random.randint(0, 255)))
            else:
                operand = seed
            const = type(operand) == int
            ops = '{}{}{}'.format(ops, random.choice(self._operators), operand)
        return '({})'.format(ops)

    def _zero(self, seed):
        return random.choice(self._zero_ops).format(x=seed)

    def _value(self, seed, value):
        value_ops = random.choice(self._value_ops)
        return value_ops.format(x=self._zero(seed), y=value)

class RenameVariablesVisitor(c_ast.NodeVisitor):
    def __init__(self, compound, prefix):
        self._prefix = prefix
        self._var_names = []
        for node in compound.block_items:
            if type(node) == c_ast.Decl and type(node.type) != c_ast.FuncDecl:
                self._var_names.append(node.name)

    def visit_TypeDecl(self, node):
        if node.declname in self._var_names:
            node.declname = node.declname + self._prefix

    def visit_ID(self, node):
        if node.name in self._var_names:
            node.name = node.name + self._prefix

class PatternVisitor(c_ast.NodeVisitor):
    def __init__(self, patterns, rounds, parent=None):
        self._parser = c_parser.CParser()
        self._ops = OperationsGenerator()
        self._patterns = patterns
        self._rounds = rounds
        self.decls = []
        if parent and parent.args:
            self._seed = parent.args.exprs[0].name
        else:
            self._seed = None

    def add_decls(self, target):
        target.ext = self.decls + target.ext

    def visit_Compound(self, node):
        rename = RenameVariablesVisitor(node, str(self._rounds))
        rename.visit(node)
        for index, child in enumerate(node.block_items):
            if type(child) == c_ast.FuncCall:
                if child.name.name == 'PT_TRASH':
                    node.block_items[index] = self._pt_trash(child)
                elif child.name.name == 'PT_ASSING_RANDOM_NUM':
                    node.block_items[index] = self._pt_assign_random_num(child)
                elif child.name.name == 'PT_ASSING_RANDOM_STR':
                    node.block_items[index] = self._pt_assign_random_str(child)
                elif child.name.name == 'PT_ASSING_CHOISE':
                    node.block_items[index] = self._pt_assign_choise(child)
        self.generic_visit(node)

    def _pt_trash(self, node):
        if self._rounds == 0:
            return c_ast.EmptyStatement()

        filename = random.choice(random.choice(self._patterns))
        with open(filename) as f:
            ast = self._parser.parse(f.read())

        code = None
        for child in ast.ext:
            if type(child) == c_ast.FuncDef and child.decl.name == 'pattern':
                code = child.body
                pattern = PatternVisitor(self._patterns, self._rounds - 1, node)
                pattern.visit(code)
                self._pt_add_decls(pattern.decls)
            elif type(child) == c_ast.Decl and type(child.type) == c_ast.FuncDecl:
                self._pt_add_decls([child])
        assert code, 'Invalid pattern: {}'.format(filename)
        return code

    def _pt_assign_random_num(self, node):
        var = node.args.exprs[0].name
        min = int(node.args.exprs[1].value, 0)
        max = int(node.args.exprs[2].value, 0)
        return self._ops.gen_rand_value(var, min, max, self._seed)

    def _pt_assign_random_str(self, node):
        var = node.args.exprs[0].name
        min = int(node.args.exprs[1].value, 0)
        max = int(node.args.exprs[2].value, 0)
        return self._ops.gen_rand_str(var, min, max, self._seed)

    def _pt_assign_choise(self, node):
        return c_ast.EmptyStatement()

    def _pt_add_decls(self, decls):
        for decl in decls:
            found = [decl for d in self.decls if d.name == decl.name]
            if not found:
                self.decls.append(decl)

def read_source_code(filename):
    includes = ''
    code = ''
    with open(filename) as f:
        for line in f.readlines():
            if line.find('#include') != -1:
                includes += line
            else:
                code += line
    return (includes, code)

def write_source_code(filename, includes, code):
    with open(filename, 'w') as f:
        f.write(includes + code)

def get_files_list(dir_path):
    files_list = []
    for root, dirs, files in os.walk(dir_path):
        if files:
            files_list.append([os.path.join(root, name) for name in files])
    return files_list

#TODO: optimize
def get_patterns(patterns_dir, max_libs, max_funcs):
    patterns = get_files_list(patterns_dir)
    if not patterns:
        return None

    libs_num = random.randint(1, max_libs) if max_libs else len(patterns)
    selected = []
    for i in range(libs_num):
        if not patterns:
            break

        lib = random.choice(patterns)
        funcs_num = random.randint(1, max_funcs) if max_funcs else len(lib)
        funcs = []
        for j in range(funcs_num):
            if not lib:
                break
            func = random.choice(lib)
            funcs.append(func)
            lib.remove(func)

        patterns.remove(lib)
        selected.append(funcs)

    return selected

def trashcode(filename, patterns_dir, rounds, max_libs=None, max_funcs=None):
    patterns = get_patterns(patterns_dir, max_libs, max_funcs)
    assert patterns, 'Patterns not found.'

    includes, code = read_source_code(filename)
    assert code, 'Invalid source code.'

    parser = c_parser.CParser()
    target = parser.parse(code)
    pattern = PatternVisitor(patterns, rounds)
    pattern.visit(target)
    pattern.add_decls(target)

    generator = c_generator.CGenerator()
    code = generator.visit(target)

    write_source_code(filename, includes, code)

#TODO: optimize
def trashimport(filename, import_dir, decl_name, max_libs=None, max_funcs=None):
    import_list = get_files_list(import_dir)
    if not import_list:
        return

    libs_num = random.randint(1, max_libs) if max_libs else len(import_list[0])
    content = '\n'
    for i in range(libs_num):
        if not import_list[0]:
            break

        importname = random.choice(import_list[0])
        with open(importname) as f:
            func_list = [s.strip() for s in f.read().splitlines()]
            assert func_list, 'Invalid import: {}.'.format(importname)

        funcs_num = random.randint(1, max_funcs) if max_funcs else len(func_list)
        for j in range(funcs_num):
            if not func_list:
                break
            funcname = random.choice(func_list)
            content += 'void *{}{}_{} = {};\n'.format(decl_name, i, j, funcname)
            func_list.remove(funcname)

        import_list[0].remove(importname)

    with open(filename, 'a') as f:
        f.write(content)

def main():
    filename = TEST_TARGET2 + '.trash'
    copyfile(TEST_TARGET2, filename)
    trashimport(filename, TEST_IMPORT, 5, 5)

    filename = TEST_TARGET + '.trash'
    copyfile(TEST_TARGET, filename)
    trashcode(filename, TEST_PATTERNS, TEST_ROUNDS)

if __name__ == '__main__':
    main()
