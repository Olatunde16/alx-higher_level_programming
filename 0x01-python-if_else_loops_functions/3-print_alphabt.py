#!/usr/bin/python3
# Author - Olutunmibi Iseoluwa
for char in range(ord('a'), ord('z') + 1):
  if chr(char) not in ['q', 'e']:
    print(chr(char), end='')
