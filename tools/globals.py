import platform, subprocess, sys

PLATFORM = sys.platform
for x in platform.uname():
    if "microsoft" in x.lower():
        PLATFORM = "windows"
        break

def IsWindows():
    return PLATFORM == "windows" or PLATFORM == "win32"

def IsLinux():
    return PLATFORM == "linux"

def IsMac():
    return PLATFORM == "darwin"