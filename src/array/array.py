

from dataclasses import dataclass
from textwrap import indent
import random

def find_by_pos(arr, pos):
    if pos < 0 or pos >= len(arr):
        return -1, "ERROR"
    
    return arr[pos], "SUCCESS"


def find_by_value(arr, value):
    for key in range(len(arr)):
        if arr[key] == value:
            return key, "SUCCESS"

    return -1, "ERROR"

def delete_by_pos(arr, pos):
    if pos < 0 or pos >= len(arr):
        return "ERROR"

    del arr[pos]
    
    return "SUCCESS"

def delete_by_value(arr, value):
    while value in arr:
        arr.remove(value)

def insert_by_pos(arr, pos, data):
    if pos < 0 or pos > len(arr):
        return "ERROR"

    arr.append(0)
    for index in range(len(arr)-1, pos, -1):
        arr[index] = arr[index-1]

    arr[pos] = data

    return "SUCESS"

def insert_by_value(arr, origin, data):
    for key in range(len(arr)):
        if arr[key-1] == origin:
            break

    if key == len(arr):
        arr.append(data)
        return "SUCESS"

    arr.append(0)
    for index in range(len(arr)-1, key, -1):
        arr[index] = arr[index-1]

    arr[key] = data

    return "SUCESS"

def main():
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    value, status = find_by_pos(arr, random.randint(1, 10))
    if status == "SUCCESS":
        print("find by pos: ", value)

    
    pos, status = find_by_value(arr, random.randint(1, 10))
    if status == "SUCCESS":
        print("find by value: ", pos)


    status = delete_by_pos(arr, random.randint(1, 10))
    if status == "SUCCESS":
        print("delete by pos: ", arr)

    delete_by_value(arr, random.randint(1, 8))
    print("delete by value: ", arr)

    status = insert_by_pos(arr, random.randint(1, 8), random.randint(1, 10))
    if status == "SUCESS":
        print("insert by pos: ", arr)

    status = insert_by_value(arr, random.randint(1, 9), random.randint(1, 10))
    if status == "SUCESS":
        print("insert by value: ", arr)


if __name__ == "__main__":
    main()