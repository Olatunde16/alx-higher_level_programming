#!/usr/bin/python3
"""Defines a JSON file-writing function"""


import json


def save_to_json_file(my_obj, filename):
    """Writes and object to a file using JSON representation"""
    with open(filename, mode="w") as f:
        json.dump(my_obj, f)
