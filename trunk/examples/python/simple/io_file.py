#!/usr/bin/python
# Filename: io_file.py

poem = '''\
Programming is fun
When the work is done
if you wanna make your work also fun:
	use Python!
'''

fout = file("poem.txt", 'w')
fout.write(poem)
fout.close()

fin = file("poem.txt")
while True:
	line = fin.readline()
	if line == '':
		break
	print line,
fin.close()
