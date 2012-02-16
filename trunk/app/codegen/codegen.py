#!/usr/bin/python

'''A code generator.'''

import os

g_header = []

def headgen(filename):
    '''Generator header file'''
    headfilename = filename + ".h"
    try:
        if os.path.exists(headfilename):
            print("This file is already exists.")
            return

        headfile = open(headfilename, 'w')
        for line in g_header:
            headfile.write(line)
        headfile.write("#ifndef\n");
        headfile.write("#define\n");
        headfile.write("#endif\n");

        headfile.close();
    except IOError, e:
        print "***file open error: ", e

def cgen():
    '''Generator c source file.'''
    filename = raw_input("Enter filename:")
    headgen(filename)

    srcfilename = filename + ".c"
    if os.path.exists(srcfilename):
        print("This file is already exists.")
        return

    fout = open(srcfilename, 'w')
    for line in g_header:
        fout.write(line)
    fout.write("#include \"\"\n")

    sel = raw_input("Add main() function or not(Y/N)?")
    if sel == 'y' or sel == 'Y':
        fout.write("int main(int argc, char *argv[])\n")
        fout.write("{\n")
        fout.write("  return 0;\n")
        fout.write("}\n")

    fout.close()

def cppgen():
    '''Generator cpp source file.'''
    classname = raw_input("Enter class name: ")

    headfilename = classname + ".h"
    srcfilename = classname + ".cpp"
    if os.path.exists(headfilename) or os.path.exists(srcfilename):
        print("This file is already exists.")
        return

    headfile = open(headfilename, 'w')
    srcfile = open(srcfilename, 'w')
    for line in g_header:
        headfile.write(line)
        srcfile.write(line)

    headfile.write("#ifndef\n");
    headfile.write("#define\n");
    headfile.write("\n")
    headfile.write("class %s\n" % classname)
    headfile.write("{\n")
    headfile.write("public:\n")
    headfile.write("  %s();\n" % classname)
    headfile.write("  ~%s();\n" % classname)
    headfile.write("protected:\n")
    headfile.write("  %s(const %s &other);\n" % (classname, classname))
    headfile.write("  %s &operator=(const %s &other);\n" % (classname, classname))
    headfile.write("private:\n")
    headfile.write("};\n")
    headfile.write("\n")
    headfile.write("#endif\n");
    headfile.close()

    srcfile.write("#include \"\"\n")
    srcfile.write("\n")
    srcfile.write("%s::%s()\n" % (classname, classname))
    srcfile.write("{\n")
    srcfile.write("}\n")
    srcfile.write("\n")
    srcfile.write("%s::~%s()\n" % (classname, classname))
    srcfile.write("{\n")
    srcfile.write("}\n")
    srcfile.close()

def main():
    '''Main function'''
    head = open("header.h", 'r')
    for line in head.readlines():
        g_header.append(line)

    # Get output type
    codetype = raw_input("Enter type(c, cpp):")
    if codetype == "c":
        cgen()
    elif codetype == "cpp":
        cppgen()
    else:
        print("Please enter a right type(c, cpp).")

if __name__ == "__main__":
    main()

