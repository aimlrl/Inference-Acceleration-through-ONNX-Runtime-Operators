from setuptools import setup, Extension
from torch.utils import cpp_extension

setup(name='repeatInterleave',
     ext_modules=[cpp_extension.CppExtension('repeatInterleave',['repeatInterleave.cpp'])],
     include_dirs = ["torch/script.h","ATen/ATen.h"],
     cmdclass = {'build_ext':cpp_extension.BuildExtension})

setup(name='reduction',
     ext_modules=[cpp_extension.CppExtension('reduction',['reduction.cpp'])],
     include_dirs = ["torch/script.h","ATen/ATen.h"],
     cmdclass = {'build_ext':cpp_extension.BuildExtension})