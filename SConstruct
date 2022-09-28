import os
import platform

env = Environment()
env['SYSTEM'] = platform.system().lower()
env['PATH'] = os.environ['PATH']
env['TARGET_ARCH'] = 'x86_64'

if env['SYSTEM'] == 'windows':
    env['MSVC_VERSION'] = '14.2'
    env.Append(CCFLAGS=["/EHsc"])

if env['SYSTEM'] in ['linux', 'darwin']:
    env['CXX'] = 'g++'
    env.Append(CCFLAGS=["-g"])

env.Program(target='CPU_Stress', source=['cpu_stress.cpp'])
