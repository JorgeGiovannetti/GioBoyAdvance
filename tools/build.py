import os
import subprocess
import sys
import globals

# Build projects/solutions

if globals.IsWindows():
    if not os.path.exists(os.getcwd() + '\\GioBoyAdvance.sln'):
        print('Generating Visual Studio solution...')
        subprocess.call('python tools\\gen.py')
    ret = subprocess.call(['msbuild.exe', 'GioBoyAdvance.sln'] + sys.argv[1:])

if globals.IsLinux():
    ret = subprocess.call(['make'] + sys.argv[1:])

if globals.IsMac():
    ret = subprocess.call(['make'] + sys.argv[1:])

sys.exit(ret)
