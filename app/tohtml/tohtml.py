#!/usr/bin/python

import cgi
import string
import token
import tokenize
import keyword
from cStringIO import StringIO

Token_Keyword = token.NT_OFFSET + 1
Token_Special = token.NT_OFFSET + 2
Token_Macro = token.NT_OFFSET + 3
highlight_style = {}
highlight_style[token.NUMBER] = '#D000D0'
highlight_style[token.STRING] = '#D000D0'
highlight_style[token.OP] = '#000000'
highlight_style[tokenize.COMMENT] = '#0000C0'
highlight_style[token.NAME] = '#202000'
highlight_style[token.ERRORTOKEN] = '#FF8080'
highlight_style[Token_Keyword] = '#FF0000'
highlight_style[Token_Special] = '#009090'
highlight_style[Token_Macro] = '#F08000'

keywords = []

class ToHtml:
    def __init__(self, srcfilename, destfilename, linenumber):
        self.source = open(srcfilename).readlines()
        self.destlines = []

        ext = srcfilename[srcfilename.rindex("."):]
        if ext == ".h" or ext == ".c" or ext == ".cpp":
            self.cstyle = True
        else:
            self.cstyle = False

        self.format(linenumber)

        # write to dest file.
        self.destfile = open(destfilename, 'w')
        for line in self.destlines:
            self.destfile.write(line)

    def format(self, linenumber):
        i = 0
        self.destlines.append('<pre style = "background-color: #F0F0C0;">\n')
        self.CComment = False
        self.CppComment = False
        for line in self.source:
            if linenumber:
                i += 1
                self.destlines.append('<span style = "color: #008000;">')
                self.destlines.append("%3d|" % i)
                self.destlines.append('</span>')

            self.pos = 0
            try:
                tokenize.tokenize(StringIO(line).readline, self)
            except:
                pass
        self.destlines.append("</pre>\n")

    def __call__(self, tokentype, tokentext, (srow, scol), (erow, ecol), line):
        if tokentype == tokenize.COMMENT and self.cstyle:
            tokentype = Token_Macro

        # comment
        if tokentext == "/" and line[scol+1] == "*":
            self.CComment = True
        elif tokentext == "//":
            self.CppComment = True
        elif self.CppComment and tokentype in [tokenize.NL, token.NEWLINE]:
            self.CppComment = False
        elif tokentext == "*" and line[scol+1] == "/" and self.CComment:
            tokentype = tokenize.COMMENT
            self.CComment = False

        if self.CComment or self.CppComment:
            tokentype = tokenize.COMMENT

        # whitespace
        oldpos = self.pos
        newpos = scol
        self.pos = newpos + len(tokentext)
        text = line[oldpos:newpos]
        self.destlines.append(text)

        # style
        if tokentype == token.NAME and keyword.iskeyword(tokentext):
            tokentype = Token_Keyword
        elif tokentype == token.NAME and is_keywords(tokentext):
            tokentype = Token_Special

        color = highlight_style.get(tokentype, highlight_style[Token_Macro])
        self.destlines.append('<span style = "color: %s;">' % color)
        self.destlines.append(cgi.escape(tokentext))
        self.destlines.append('</span>')

def init_keywords():
    for keyword in open("keywords").readlines():
        if(keyword[0] == '#'):
            continue
        keywords.append(keyword[:keyword.find('\n')])

def is_keywords(text):
    if text in keywords:
        return True
    return False

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

    init_keywords()
    ToHtml(srcfilename, destfilename, linenumber)

    print("Done.")

if __name__ == "__main__":
    main()

