#!/usr/bin/python
# -*- coding=utf-8 -*-

# string.capitalize()
strone = "this is a simple string."
print(strone)
strtwo = strone.capitalize()
print(strtwo)
print

# string.center(width)
# string.ljust(width)
# string.rjust(width)
# string.zfill(width)
strone = "a string."
print("[%s]" % strone)
strtwo = strone.center(20)
print("[%s]" % strtwo)
strtwo = strone.ljust(20)
print("[%s]" % strtwo)
strtwo = strone.rjust(20)
print("[%s]" % strtwo)
strtwo = strone.zfill(20)
print("[%s]" % strtwo)

print

# string.count(str, beg=0, end=len(string))
strone = "this is a simple string."
print(strone.count("is")),
print(strone.count("i", 0, 6))
print

# string.encode(encoding='UTF-8', errors='strict')
# string.decode(encoding='UTF-8', errors='strict')
# common using: encode write read decode
strone = u"中文"
print(strone)
strtwo = strone.encode('utf-8')
print(strtwo)
strtwo = strtwo.decode('utf-8')
print(strtwo)
print

# string.endswith(obj, beg=0, end=len(string))
# string.startswith(obj, beg=0, end=len(string))
strone = "This is a simple string."
rt = strone.startswith("this")
print(rt)
rt = strone.endswith(".")
print(rt)
print

# string.expandtabs(tabsize=8)
strone = "a string;\tanother string."
print(strone)
strtwo = strone.expandtabs(4)
print(strtwo)
print

# string.find(str, beg=0, end=len(string))
# string.rfind(str, beg=0, end=len(string))
strone = "This is a simple string."
i = strone.find("s")
print(i),
i = strone.rfind("s")
print(i),
i = strone.find("b")
print(i)

# string.index(str, beg=0, end=len(string))
strone = "This is a simple string."
i = strone.index("a") # if use index("b"), an exception thrown
print(i),
i = strone.rindex("a")
print(i)

# string.isalnum()
strone = "string234"
print(strone.isalnum())
strone = "string234."
print(strone.isalnum())

# string.isalpha()
strone = "string"
print(strone.isalpha())
strone = "string123"
print(strone.isalpha())

# string.isdigit()
strone = "23244"
print(strone.isdigit())
strone = "s2344"
print(strone.isdigit())

# string.islower()
# string.isupper()
strone = "this is a simple string."
print(strone.islower())
print(strone.isupper())
strone = "This is a simple string."
print(strone.islower())
print(strone.isupper())

# string.isspace()
strone = " \t\n"
print(strone.isspace())
print

# string.join(seq)
seq = ["Red","Green","Blue","Yello","White"]
print("-".join(seq))
print

# string.lower()
# string.upper()
# string.swapcase()
# string.title()
# string.istile()
strone = "This is a simple string."
print(strone.upper())
print(strone.lower())
print(strone.swapcase())
print(strone.title())
print(strone.istitle())
print

# string.lstrip()
# string.rstrip()
# string.strip()
strone = "  This is a simple string. \t"
print("[%s]" % strone)
print("[%s]" % strone.lstrip())
print("[%s]" % strone.rstrip())
print("[%s]" % strone.strip())
print

# string.partition(str)
# string.rpartition(str)
strone = "This is a simple string."
parts = strone.partition("is")
print(parts)
parts = strone.rpartition("is")
print(parts)
print

# string.replace(str1, str2, num=string.count(str1))
strone = "this is a simple string."
print(strone.replace("t", "T"))
print(strone.replace("t", "T", 1))
print

# string.split(str=" ", num=string.count(str))
strone = "this is a simple string."
print(strone.split())
strone = "the first line\nthe secondline\nthe third line.\n"
print(strone.splitlines())
print

# string.translate(str, del="")
