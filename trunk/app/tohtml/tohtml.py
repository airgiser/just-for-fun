#!/usr/bin/python

import cgi

class ToHtml:
    def __init__(self, srcfilename, destfilename):
        self.srcfile = open(srcfilename)
        self.destlines = []
        self.destfile = open(destfilename, 'w')

        i = 0
        self.destlines.append('<pre style = "background-color: #cdcdb4;">\n')
        for line in self.srcfile.readlines():
            i += 1
            self.destlines.append('<span style = "color: #ff40ff;">')
            self.destlines.append("%3d|" % i)
            self.destlines.append('</span>')
            self.format(cgi.escape(line))
        self.destlines.append("</pre>\n")

        for line in self.destlines:
            self.destfile.write(line)

    def format(self, line):
        if line[0] == '#':
            line = '<span style = "color: #0000ff;">' + line[:line.find('\n')]
            line += '</span>\n'
        self.destlines.append(line)

    def __call__(self, tokentype, tokentext, (srow, scol), (erow, ecol), line):
        if tokentype == token.STRING:
#            self.destlines.append(

def main():
    import os, sys
    if(len(sys.argv) != 3):
        srcfilename = input("Enter the source file name:")
        destfilename = input("Enter the output file name:")
    else:
        srcfilename = sys.argv[1]
        destfilename = sys.argv[2]
    
    ToHtml(srcfilename, destfilename)
    print("Done.")

if __name__ == "__main__":
    main()
