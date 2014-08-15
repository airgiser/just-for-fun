import os
import csv
import sqlite3

def csv2sqlite(csvfilename, dbfilename):
  # csv reader
  reader = csv.reader(open(csvfilename), delimiter=',')

  # sqlite connection
  conn = sqlite3.connect(os.path.join(os.getcwd(),dbfilename))
  cursor = conn.cursor()

  rowNum = 0
  for row in reader:
    if rowNum == 0:
      #create table
      script = "CREATE TABLE parcel("
      for i in row:
        script += i + " INTEGER,"
      script = script[:-1]
      script += ")"
      cursor.execute(script)
      print script
    else:
      #insert rows 
      script = "INSERT INTO parcel values(%s)" % ",".join(len(row)*"?")
      cursor.execute(script,  row)
    rowNum = rowNum + 1
  conn.commit();

  script = "SELECT * from parcel order by RSize"
  cursor.execute(script)
  for i in cursor:
    print i

  cursor.close();

def main():
  csvfilename = "parcel.csv"
  dbfilename = "parcel.db"
  if os.path.exists(dbfilename):
    print "the sqlite db is existed."
  else:
    csv2sqlite(csvfilename, dbfilename)

if __name__ == "__main__":
  main()
