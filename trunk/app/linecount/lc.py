#!/usr/bin/python

import sys
import os

extensions = [".c", ".cpp", ".h", ".py"]

def is_valid_extension(filename):
    try:
        extension = filename[filename.rindex('.'):]
        if(extensions.index(extension) >= 0):
            return True
        else:
            return False
    except:
        return False

def get_line_count(filename):
    count = 0
    fin = open(filename)
    for line in fin.xreadlines():
        count += 1
    return count

def main():
    linecount = 0
    filecount = 0
    
    curdir = os.getcwd()
    for root, dirs, files in os.walk(curdir):
        for filename in files:
            if(is_valid_extension(filename)):
                filecount += 1
                fullname = (root + '/' + filename).lower()
                count = get_line_count(fullname)
                linecount += count
                print("%s: %d" % (filename, count))

    print('-' * 10 + 'total' + '-' * 10)
    print("file count: %d" % filecount)
    print("line count: %d" % linecount)
            
if __name__ == '__main__':
    main()
