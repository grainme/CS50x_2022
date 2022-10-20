import csv
import re
import SQL
import sqlite3
# with open("test.csv","r") as file:
#     reader = csv.reader(file)
#     next(reader)
#     for row in reader:
#         if re.search(r".?MAROUANE.?$",row[0],re.IGNORECASE):
#             print(row[0])

db = SQL("sqlite:///C:/sqlite/names_1.db")
name = input("Name: ").strip()
rows = db.execute("SELECT COUNT(*) FROM names_1 WHERE name LIKE ?",name)
print(rows)
