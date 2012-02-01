#!/usr/bin/python
'''Read and display text file'''

# Get file name
filename = raw_input("Enter a file name:")
print(50 * '*')

# try to open file for reading
try:
    fin = open(filename, 'r')
except IOError, e:
    print "***file open error:", e
else:
    # Get file content.
    while True:
        line = fin.readline()
        if(line == ""):
            break;
        print line,
    
    print(50 * '*')
    fin.close()
finally:
    print("End.")

