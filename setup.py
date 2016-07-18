from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools
import subprocess
# import pkgconfig # helper class to get ibex flags and libs
__version__ = '0.1.0a'


class get_pybind_include(object):
    """Helper class to determine the pybind11 include path
    The purpose of this class is to postpone importing pybind11
    until it is actually installed, so that the ``get_include()``
    method can be invoked. """

    def __init__(self, user=False):
        self.user = user

    def __str__(self):
        import pybind11
        return pybind11.get_include(self.user)


def get_ibexflags():
    try:
      result = subprocess.check_output(["pkg-config", "--cflags", "--libs", "ibex"])
      result = result.decode('utf-8').rstrip()
    except:
      result = "-libex -lprim -lm"

    # print(result)
    ret = {'library_dirs': [], 'include_dirs':[], 'libraries': [], 'cpp_flag':[]}
    for s in result.split(' '):
      if '-I' in s:
        ret['include_dirs'].append(s)
      elif '-L' in  s:
        ret['library_dirs'].append(s)
      elif '-l' in s[:2]:
        ret['libraries'].append(s)
      else:
        ret['cpp_flag'].append(s)

    return ret




ext_modules = [
    Extension(
        'pyibex_geometry.geometry',
        [
          'src/polar/ibex_CtcAngle.cpp',
          'src/polar/ibex_CtcPolar.cpp',
          'src/polar/ibex_SepPolarXY.cpp',
          'src/polygon/ibex_CtcSegment.cpp',
          'src/polygon/ibex_PdcInPolygon.cpp',
          'src/polygon/ibex_SepPolygon.cpp',
          'src/pyibex_geometry.cpp',
        ],
        include_dirs=[
            'src',
            'src/polar',
            'src/polygon',
            'pybind11/include'
        ],
        language='c++'
    )
]


# As of Python 3.6, CCompiler has a `has_flag` method.
# cf http://bugs.python.org/issue26689
def has_flag(compiler, flagname):
    """Return a boolean indicating whether a flag name is supported on
    the specified compiler.
    """
    import tempfile
    with tempfile.NamedTemporaryFile('w', suffix='.cpp') as f:
        f.write('int main (int argc, char **argv) { return 0; }')
        try:
            compiler.compile([f.name], extra_postargs=[flagname])
        except setuptools.distutils.errors.CompileError:
            return False
    return True


def cpp_flag(compiler):
    """Return the -std=c++[11/14] compiler flag.
    The c++14 is prefered over c++11 (when it is available).
    """
    if has_flag(compiler, '-std=c++14'):
        return '-std=c++14'
    elif has_flag(compiler, '-std=c++11'):
        return '-std=c++11'
    else:
        raise RuntimeError('Unsupported compiler -- at least C++11 support '
                           'is needed!')

class BuildExt(build_ext):
    """A custom build extension for adding compiler-specific options."""
    c_opts = {
        'msvc': ['/EHsc'],
        'unix': [],
    }

    if sys.platform == 'darwin':
        c_opts['unix'] += ['-stdlib=libc++', '-mmacosx-version-min=10.7']

    def build_extensions(self):
        ct = self.compiler.compiler_type
        opts = self.c_opts.get(ct, [])
        if ct == 'unix':
            opts.append('-DVERSION_INFO="%s"' % self.distribution.get_version())
            opts.append(cpp_flag(self.compiler))
            if has_flag(self.compiler, '-fvisibility=hidden'):
                opts.append('-fvisibility=hidden')
        elif ct == 'msvc':
            opts.append('/DVERSION_INFO=\\"%s\\"' % self.distribution.get_version())

        ibex_config = get_ibexflags()
        for d in ibex_config['include_dirs']:
          self.compiler.add_include_dir(d.replace('-I',""))
        for d in ibex_config['library_dirs']:
          self.compiler.add_library_dir(d.replace("-L",""))
        for l in ibex_config['libraries']:
          self.compiler.add_library(l.replace('-l',""))
        for f in ibex_config['cpp_flag']:
          opts.append(f)

        for ext in self.extensions:
            ext.extra_compile_args = opts
        build_ext.build_extensions(self)


setup(
    name='pyibex_geometry',
    version=__version__,
    author='Benoit Desrochers',
    author_email='ben.ensta@gmail.com',
    url='https://github.com/benEnsta/pyIbex',
    description='PyIbex geometry package based on ibex-geometry',
    long_description='',
    ext_modules=ext_modules,
    install_requires=['pyibex'],
    cmdclass={'build_ext': BuildExt},
    test_suite="pyibex_geometry.tests",
    # package_dir={'pyibex_geometry': 'python/pyibex_geometry'},
    packages=['pyibex_geometry', 'pyibex_geometry.examples'],
    license="LGPL v3",



    # zip_safe=False,
)
