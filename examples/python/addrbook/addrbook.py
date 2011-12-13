#!/usr/bin/python
# Filename: addrbook.py

import sys
import cPickle as p

class Person:
	'''
	Contact information of a person

	name, phone, email, address
	'''
	def __init__(self, name, phone, email = '', address = ''):
		self.name = name
		self.phone = phone
		self.email = email
		self.address = address
	def __str__(self):
		output = '\tName:' + self.name + '\n' + \
			 '\tPhone: ' + self.phone + '\n' + \
			 '\tEmail: ' + self.email + '\n' + \
			 '\tAddress: ' + self.address + '\n'
		return output


def addr_find(name, book):
	if len(name) == 0:
		print 'Invalid Name!'
		return

	if name in book:
		print
		print book[name]
	else:
		print 'Not find'

def addr_add(book):
	name = raw_input("Please enter the name:")
	if len(name) < 1:
		print "The name is too short"

	phone = raw_input("Please enter phone:")
	if len(phone) < 3:
		print "This phone is too short"

	mail = raw_input("Please enter email:")
	address = raw_input("Please enter address:")

	newperson = Person(name, phone, mail, address)
	addrbook[newperson.name] = newperson

def addr_edit(name, book):
	if len(name) == 0:
		print 'Invalid Name!'
		return

	if name in book:
		print
		print book[name]

		while True:
			line = raw_input('Enter the field you want to edit:')
			if line == 'Phone':
				phone = raw_input('Please Enter the new phone:')
				book[name].phone = phone
			elif line == 'Email':
				email = raw_input('Please Enter the new Email:')
				book[name].email = email
			elif line == 'Address':
				address = raw_input('Please Enter the new \
						Address:')
				book[name].address = address
			else:
				break
	else:
		print 'Invalid Name!'

# The main scripts start here
print 60 * '='
print '\t [Address Book]\n'
print 'Type "find" to get contact information of someone'
print 'Type "add" to add a contact information'
print 'Type "edit" to edit an exist contact information'
print 'Type "print" to print the address book'
print 'Type "quit" to quit this program'
print 60 * '='

addrfile = 'addrbook.data'

# Read address book from file
try:
	f = file(addrfile, 'r')
	addrbook = p.load(f)
	f.close()
except:
	print 'load addrbook failed.'
	addrbook = {}

# If the addrbook is empty, insert my information
if len(addrbook) == 0:
	mine = Person('airgis', '123456', 'airgis@163.com', 'guangzhou, china')
	addrbook[mine.name] = mine
	f= file(addrfile, 'w')
	p.dump(addrbook, f)
	f.close()

# Process commands
while True:
	line = raw_input(">>>")

	if line == 'quit':
		sys.exit()
	elif line[:4] == 'find':
		name = line[5:]
		addr_find(name, addrbook)
	elif line == 'print':
		print
		for name, oneperson in addrbook.items():
			print oneperson
	elif line[:4] == 'edit':
		name = line[5:]
		addr_edit(name, addrbook)

		f = file(addrfile, 'w')
		p.dump(addrbook, f)
		f.close()
	elif line == 'add':
		addr_add(addrbook)

		f = file(addrfile, 'w')
		p.dump(addrbook, f)
		f.close()
	else:
		print 'Invalid command!'
