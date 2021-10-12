import os, subprocess, sys

def runCommand(cmds):
    cmds[0] = "./{}/{}.py".format('tools', cmds[0])
    if os.path.exists(os.getcwd() + cmds[0]):
        ret = subprocess.call(['python'] + cmds)
    else:
        print('Invalid command: ', *cmds)
        ret = -1


if len(sys.argv) > 1:
    runCommand(sys.argv[1:])