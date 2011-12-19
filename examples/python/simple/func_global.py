#!/usr/bin/python
# Filename: func_global.py

def func():
    global x
    print 'x is', x
    x = 2
    print 'x is change to', x

x = 50
func()
print 'x is now',x
