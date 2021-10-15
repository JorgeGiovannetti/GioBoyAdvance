import os
import shutil


def removeFile(filename):
    try:
        os.remove(filename)
        return "Removed file: %s" % (filename)
    except OSError as e:
        return "Error: %s - %s." % (e.filename, e.strerror)


def removeFolder(dirname):
    try:
        shutil.rmtree(dirname)
        return "Removed dir: %s" % (dirname)
    except OSError as e:
        return "Error: %s - %s." % (e.filename, e.strerror)


files = [
    'GioBoyAdvance.sln',
    'GioBoyAdvance.vcxproj',
    'GioBoyAdvance.vcxproj.filters',
    'vendor/glad/glad.vcxproj',
    'vendor/glad/glad.vcxproj.filters'
]

dirs = [
    'bin',
    'bin-obj',
    'vendor/glad/bin',
    'vendor/glad/bin-obj'
]

filesDeleted = 0

for f in files:
    res = removeFile(f)
    if res[:5] != "Error":
        filesDeleted += 1

dirsDeleted = 0

for d in dirs:
    removeFolder(d)
    if res[:5] != "Error":
        dirsDeleted += 1

print('Cleaned up %s files and %s directories' % (filesDeleted, dirsDeleted))
