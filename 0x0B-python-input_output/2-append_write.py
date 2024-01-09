#!/usr/bin/python3
"""Defines a file-appending function"""


def append_write(filename="", text=""):
    """Appends a string at the end of the the UTF-8 text file
    """
    with open(filename, mode="a", encoding="utf-8") as f:
        return f.write(text)
