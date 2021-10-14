import os
import subprocess
import sys
import globals

# Run project


def findExecutable(name, path):
    for root, dirs, files in os.walk(path):
        if name in files:
            return os.path.join(root, name)


if globals.IsWindows():
    ret = 0
    if not os.path.exists(os.getcwd() + '/bin'):
        print('Building project...')
        ret = subprocess.call('python tools\\build.py')
    executable = findExecutable('GioBoyAdvance.exe', os.getcwd() + '/bin')
    if executable is not None:
        ret = subprocess.call(executable)

sys.exit(ret)
