#!/usr/bin/python

from decimal import Decimal

print(hex(255))
print(hex(65535*2))
print(oct(255))
print(oct(65535*2))

print(ord('a'))
print(ord('A'))
print(chr(97))
print(chr(65))

dec = Decimal('0.1')
print(dec)
dec += Decimal('1.0')
print(dec)
