import subprocess, sys
import globals

# Generate projects/solutions

if globals.IsWindows():
    ret = subprocess.call("vendor\\bin\\premake\\premake5.exe vs2017")

if globals.IsLinux():
    ret = subprocess.call("vendor\\bin\\premake\\premake5.linux gmake2")

if globals.IsMac():
    ret = subprocess.call("vendor\\bin\\premake\\premake5 gmake2")
    if ret == 0:
        ret = subprocess.call("vendor\\bin\\premake\\premake5 xcode4")

sys.exit(ret)