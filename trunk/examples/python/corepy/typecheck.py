#!/usr/bin/python

def displayNumType(val):
    print val, 'is',
    if isinstance(val, (int, long, float, complex)):
        print 'a number of type:', type(val).__name__
    else:
        print 'not a number at all!'

displayNumType(23)
displayNumType(999999999999999999999L)
displayNumType(23.3)
displayNumType(-2+3.2j)
displayNumType('string')
