#/usr/bin/python

'''This is a simple module,
This is the module documentation'''

# Module imports
import sys
import os

# Global varialble declarations
debug = True

# Class declarations
class FooClass:
    '''Class documentation'''
    pass

# Function declarations
def test():
    '''Function documentation'''
    foo = FooClass()

    if debug:
        print("This is a string.")

# body
if __name__ == '__main__':
    test()

