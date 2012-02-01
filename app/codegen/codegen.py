#!/usr/bin/python

'''A code generator.'''

import os

def isfileexists(filename):
    if os.path.exists(filename):
        print("This file is already exists.")

def getfilename():
    '''Get file name'''
    filename = raw_input("Enter filename:")
    return filename

def headgen():
    '''Generator header file'''
    filename = getfilename() + ".h"
    try:
        head = open("header.h", 'r')
        fout = open(filename, 'w')
    except IOError, e:
        print "***file open error: ", e

def cgen():
    '''Generator c source file.'''
    filename = getfilename() + ".c"

def cppgen():
    '''Generator cpp source file.'''
    filename = getfilename() + ".cpp"

def main():
    '''Main function'''

    # Get output type
    codetype = raw_input("Enter type(c, cpp):")
    if codetype == "c":
        headgen()
        cgen()
    elif codetype == "cpp":
        headgen()
        cppgen()
    else:
        print("Please enter a right type(c, cpp).")

if __name__ == "__main__":
    main()

