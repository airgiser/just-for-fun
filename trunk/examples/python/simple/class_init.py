#!/usr/bin/python
# Filename: class_init.py

class Person:
    def __init__(self, name):
        self.name = name
    def sayhello(self):
        print "hello,", self.name

p = Person('python')
p.sayhello()
