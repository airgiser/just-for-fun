#! /usr/bin/python

import os
import stat

fileList = []
def filecallback(path, size):
  fileList.append((path,size))

def walkdir(root, level, callback):
  for path in os.listdir(root):
    fullPath = os.path.join(root, path)
    st = os.stat(fullPath)
    mode = st[stat.ST_MODE]

    # we can os.path.isfile() and os.path.isdir() also
    if stat.S_ISDIR(mode) and path[0] != '.':
      print((level*"  ") + "[" + path + "]")
      walkdir(fullPath, level+1, callback)
    elif stat.S_ISREG(mode):
      print((level*"  ") + path + "  " + str(st.st_size) + " bytes")
      callback(path, st.st_size)

def main():
  path = raw_input("Please enter a path:")
  walkdir(path, 0, filecallback)

  oneFile = file("sortedBySize.file", "w")
  for afile in sorted(fileList, key = lambda element: element[1]):
    oneFile.write(afile[0] + "  " + str(afile[1]) + " bytes\n")
  oneFile.close()

  anotherFile = file("sortedByName.file", "w")
  for afile in sorted(fileList, key = lambda element: element[0]):
    anotherFile.write(afile[0] + "  " + str(afile[1]) + " bytes\n")
  anotherFile.close()

if __name__ == "__main__":
  main()
