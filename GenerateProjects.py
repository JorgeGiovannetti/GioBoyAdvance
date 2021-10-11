import platform, subprocess, sys

PLATFORM = sys.platform
for x in platform.uname():
    if "microsoft" in x.lower():
        PLATFORM = "windows"
        break

if PLATFORM == 'windows' or PLATFORM == 'win32':
    ret = subprocess.call("vendor\\bin\\premake\\premake5.exe vs2017")

if PLATFORM == 'linux':
    ret = subprocess.call("vendor\\bin\\premake\\premake5.linux gmake2")

if PLATFORM == 'darwin':
    ret = subprocess.call("vendor\\bin\\premake\\premake5 xcode4")
    if ret == 0:
        ret = subprocess.call("vendor\\bin\\premake\\premake5 xcode4")

sys.exit(ret)