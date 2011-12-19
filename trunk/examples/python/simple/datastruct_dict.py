#!/usr/bin/python
# Filename: datastruct_dict.py

addrbook = {    'Swaroop'   : 'swaroopch@buyt.info',
                'Larry'     : 'larry@wall.org',
                'Matsumoto' : 'matz@ruby.ogr',
                'Spammer'   : 'spammer@hot.com'
}

print "Swaroop's address is %s" % addrbook['Swaroop']

addrbook['airgis'] = 'airgis@163.com'

del addrbook['Spammer']

print '\nThere are %d contact in the address book\n' % len(addrbook)

for name, address in addrbook.items():
    print 'Contact %s at %s' % (name, address)

print ''
for item in addrbook:
    print '[%s, %s]' % (item, addrbook[item])

if 'airgis' in addrbook:
    print "\nairgis's address is %s" % addrbook['airgis']
