#!/usr/bin/python

import cgi
import string
import token
import tokenize
import keyword
from cStringIO import StringIO

Token_Keyword = token.NT_OFFSET + 1
Token_Special = token.NT_OFFSET + 2
Token_Text = token.NT_OFFSET + 3
highlight_style = {}
highlight_style[token.NUMBER] = '#D000D0'
highlight_style[token.STRING] = '#D000D0'
highlight_style[token.OP] = '#000000'
highlight_style[tokenize.COMMENT] = '#0000C0'
highlight_style[token.NAME] = '#202000'
highlight_style[token.ERRORTOKEN] = '#FF8080'
highlight_style[Token_Keyword] = '#FF0000'
highlight_style[Token_Special] = '#009090'
highlight_style[Token_Text] = '#000000'

SpecialWords = ["self", "True", "true", "False", "false"]
SpecialWords.append("input")
SpecialWords.append("raw_input")
SpecialWords.append("open")
SpecialWords.append("file")

class ToHtml:
    def __init__(self, srcfilename, destfilename, linenumber):
        self.source = open(srcfilename).readlines()
        self.destlines = []
        self.format(linenumber)

        self.destfile = open(destfilename, 'w')
        for line in self.destlines:
            self.destfile.write(line)

    def format(self, linenumber):
        i = 0
        self.destlines.append('<pre style = "background-color: #F0F0C0;">\n')
        for line in self.source:
            if linenumber:
                i += 1
                self.destlines.append('<span style = "color: #008000;">')
                self.destlines.append("%3d|" % i)
                self.destlines.append('</span>')

            self.pos = 0
            tokenize.tokenize(StringIO(line).readline, self)
        self.destlines.append("</pre>\n")

    def __call__(self, tokentype, tokentext, (srow, scol), (erow, ecol), line):
        # new line
        if tokentype in [token.NEWLINE, tokenize.NL]:
            self.destlines.append(tokentext)
            return

        # whitespace
        oldpos = self.pos
        newpos = scol
        self.pos = newpos + len(tokentext)
        text = line[oldpos:newpos]
        self.destlines.append(text)

        # style
        if tokentype == token.NAME and keyword.iskeyword(tokentext):
            tokentype = Token_Keyword
        elif tokentext in SpecialWords:
            tokentype = Token_Special
        color = highlight_style.get(tokentype, highlight_style[Token_Text])
        self.destlines.append('<span style = "color: %s;">' % color)
        self.destlines.append(cgi.escape(tokentext))
        self.destlines.append('</span>')

def main():
    import os, sys
    if(len(sys.argv) != 3):
        srcfilename = input("Enter the source file name:")
        destfilename = input("Enter the output file name:")
    else:
        srcfilename = sys.argv[1]
        destfilename = sys.argv[2]

    select = raw_input("Add line number or not(Y/N)?")
    linenumber = False
    if(select.lower() == 'y'):
        linenumber = True
    ToHtml(srcfilename, destfilename, linenumber)

    print("Done.")

if __name__ == "__main__":
    main()

