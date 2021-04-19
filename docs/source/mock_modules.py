#!/usr/bin/env python

import inspect
import pathlib
import re
import sys

import sdf_tools

mock_name = '_sdf_tools'

def simplify_docstring(docstr):
    if docstr is None:
        return None

    strip_self = re.sub('self:\s+libsdf_tools[^\s\)]+\s+', '', docstr)
    strip_lib  = re.sub('libsdf_tools\.', '', strip_self)
    return strip_lib

def class_members(cls):
    return inspect.getmembers(cls, lambda x : inspect.isfunction(x) or
                              ( hasattr(x, '__name__') and hasattr(cls, x.__name__) and
                                type(getattr(cls, x.__name__)).__name__ == 'instancemethod') )

def class_properties(cls):
    return inspect.getmembers(cls, lambda x : x.__class__.__name__ == 'property')



def genmodule(name, fname, needfuncs):
    classes = inspect.getmembers(sys.modules[name], inspect.isclass)
    classes = sorted(classes, key = lambda cls: len(cls[1].mro()))

    fout = open(fname, 'w')

    for cname, cls in classes:
        base = ', '.join( [b.__name__ for b in cls.__bases__ if 'pybind11' not in b.__name__] )

        if len(base) > 0:
            signature = '%s(%s)' % (cname, base)
        else:
            signature = cname

        print('class %s:' % signature, file=fout)
        print('    r"""%s\n    """' % simplify_docstring(cls.__doc__), file=fout)

        members = class_members(cls)
        for mname, m in members:
            if mname == '__init__' or mname[0:2] != '__':
                print('    def %s():' % mname, file=fout)
                print('        r"""%s\n        """' % simplify_docstring(m.__doc__), file=fout)
                print('        pass\n', file=fout)

        for pname, p in class_properties(cls):
            print('    @property', file=fout)
            print('    def %s():' % pname, file=fout)
            print('        r"""%s\n        """' % simplify_docstring(p.__doc__), file=fout)
            print('        pass\n', file=fout)


    if needfuncs:
        funcs = inspect.getmembers(sys.modules[name], inspect.isfunction)

        if len(funcs) > 0:
            print('\n# Functions\n', file=fout)

        for fname, f in funcs:
            if fname[0:2] != '__':
                print('def %s():' % fname, file=fout)
                print('    r"""%s\n    """' % simplify_docstring(f.__doc__), file=fout)
                print('    pass\n', file=fout)


    print('', file=fout)
    fout.close()

pathlib.Path(mock_name).mkdir(parents=True, exist_ok=True)
genmodule('sdf_tools', mock_name + '/__init__.py', False)


submodules = inspect.getmembers(sys.modules['sdf_tools'],
                                lambda member: inspect.ismodule(member)
                                and 'sdf_tools' in member.__name__ )

for mname, m in submodules:
    subpath = mock_name + '/' + mname
    pathlib.Path(subpath).mkdir(parents=True, exist_ok=True)
    genmodule('sdf_tools.' + mname, subpath + '/__init__.py', True)
