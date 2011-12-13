#!/usr/bin/python
# Filename: base_continue.py

while True:
	s = raw_input('Enter something:')

	if(s == 'quit'):
		break;
	if(len(s) < 3):
		continue;

	print 'The length of this string is', len(s)
print 'Done'
