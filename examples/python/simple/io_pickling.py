#!/usr/bin/python
# Filename: io_pickling.py

import cPickle as p

shoplistfile = 'shoplistfile.data'

shoplist = ['apple', 'mango', 'carrot']

f = file(shoplistfile, 'w')
p.dump(shoplist, f)
f.close()

del shoplist

f = file(shoplistfile)
storedlist = p.load(f)
print storedlist
f.close()

