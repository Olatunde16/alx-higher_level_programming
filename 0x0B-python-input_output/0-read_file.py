#!/usr/bin/python3
"""A function that reads text file"""


def read_file(filename=""):
    """Prints the content of the UTF-8 text file to stdout"""
    with open(filename, encoding="utf-8") as f:
        print(f.read(), end="")
