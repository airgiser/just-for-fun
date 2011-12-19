#!/usr/bin/python
# Filename: datastruct_str_methods.py

name = 'helloworld'
if name.startswith('hel'):
    print 'Yes, the string starts with "hel"'
if 'a' in name:
    print 'Yes, it contains the string "a"'
if name.find('wor') != -1:
    print 'Yes, it contains the string "wor"'

delimiter = '_*_'
mylist = ['brazil', 'russia', 'india', 'china']
print delimiter.join(mylist)

