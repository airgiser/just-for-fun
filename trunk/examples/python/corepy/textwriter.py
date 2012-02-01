#!/usr/bin/python

'''Create text file'''

import os

# Get filename
filename = raw_input("Enter the filename:")
if os.path.exists(filename):
    print "open a exists file"
else:
    print "open a new file"

# Get file content
contents = []
print("Enter the content(Enter q to quit):")
while True:
    strline = raw_input(">>>")
    if(strline == "q"):
        break;
    contents.append(strline)

# Write to file
fout = open(filename, 'a')
fout.writelines(["%s%s" % (line, os.linesep) for line in contents])
fout.close()

print("Done!")



