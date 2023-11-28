#!/usr/bin/python3
# Author - Olutunmibi Iseoluwa

"""Print numbers 0 to 98 in decimal and hexadecimal."""
for number in range(0, 99):
    print(f"{num} = 0x{num:02X}", end='\n' if num == 98 else '')
