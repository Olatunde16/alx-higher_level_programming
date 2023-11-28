#!/usr/bin/python3
# Author - Olutunmibi Iseoluwa
for tens in range(10):
  for ones in range(tens + 1, 10):
    print(f"{tens}{ones}", end=", " if (tens, ones) != (9, 8) else "\n")
