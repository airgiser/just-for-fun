#!/usr/bin/python
# Filename: std_using_os.py

import os

print '\nCurrent OS is', os.name
print '\nCurrent directory is', os.getcwd()
print '\n[Files&Directorys]'
dirlist = os.listdir(os.getcwd())
for item in dirlist:
    if os.path.isfile(item):
        print '\tFile: ',
    elif os.path.isdir(item):
        print '\tDir:  ',
    print item

print
curpyfile = os.getcwd() + os.sep + 'std_using_os.py'
print 'Current python file name is', curpyfile


ls = os.path.split(curpyfile)
print '\nDirectory of this python file is "%s", \
\nFile name of current python file is"%s"\n' % ls
