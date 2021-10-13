import os
import shutil

def removeFile(filename):    
    try:
        os.remove(filename)
    except OSError as e:
        print ("Error: %s - %s." % (e.filename, e.strerror))

def removeFolder(dirname):
    try:
        shutil.rmtree(dirname)
    except OSError as e:
        print ("Error: %s - %s." % (e.filename, e.strerror))

files = ['GioBoyAdvance.sln', 'GioBoyAdvance.vcxproj', 'GioBoyAdvance.vcxproj.filters', 'GioBoyAdvance.vcxproj.user']
dirs = ['bin', 'bin-obj']

for f in files:
    removeFile(f)

for d in dirs:
    removeFolder(d)
