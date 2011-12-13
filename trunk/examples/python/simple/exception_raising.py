#!/usr/bin/python
# Filename: exception_raising.py

class ShortInputException(Exception):
	def __init__(self, length, atleast):
		Exception.__init__(self)
		self.length = length
		self.atleast = atleast

try:
	s = raw_input('Entering something --> ')
	if len(s) < 3:
		raise ShortInputException(len(s), 3)
except EOFError:
	print "EOF Error!"
except ShortInputException, x:
	print "ShortInputException: The input was of length %d, \
was expecting at least %d" % (x.length, x.atleast)
else:
	print "Done"
