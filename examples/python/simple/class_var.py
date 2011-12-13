#!/usr/bin/python
# Filename: class_var.py

class Person:
	'''Represents a person.'''
	population = 0
	def __init__(self, name):
		'''Initializing the person's data.'''
		self.name = name
		print '(Initializing %s)' % self.name

		# When this person is created, he/she
		# adds to the population
		Person.population += 1
	
	def __del__(self):
		'''I am dying.'''
		print '%s says bye.' % self.name

		Person.population -= 1

		if Person.population == 0:
			print 'I am the last one.'
		else:
			print 'There are still %d people left.' % Person.population
	
	def sayHello(self):
		'''Greeting by the person.

		Really, that's all it does.'''
		print 'Hello, this is %s.' % self.name

	def howMany(self):
		'''Prints the current population.'''
		if Person.population == 1:
			print 'I am the only person here.'
		else:
			print 'We have %d persons here.' % Person.population

swaroop = Person('Swaroop')
swaroop.sayHello()
swaroop.howMany()

kalam = Person('Abdul Kalam')
kalam.sayHello()
kalam.howMany()

swaroop.sayHello()
swaroop.howMany()

