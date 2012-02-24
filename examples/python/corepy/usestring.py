#!/usr/bin/python
print("hello," + " " + "world" + "!")
print(" ".join(("hello,", "world!")))
print("%s, %s!" % ("hello", "world"))

print("\ns")
print(r"\ns")
rstr = "~\doc\temp\rookie"
rstr = r"~\doc\temp\rookie"

import re
m = re.search(r"\\[nrt]", r"This is a string.\t\n")
if m is not None:
    print(m.group())

print(u"abcd")
print(ur"This is a string.\n")
