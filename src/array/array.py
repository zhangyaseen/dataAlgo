

from textwrap import indent
import random


def find_val(arr, value):
    print("arr:", arr, ", find:", value)
    for key in range(len(arr)):
        if arr[key] == value:
            return key

    return -1


def del_val(arr, value):
    print("arr:", arr, ", del:", value)
    for key in range(len(arr)):
        if arr[key] == value:
            break

    for index in range(key, len(arr)-1):
        arr[index] = arr[index+1]

    return arr

def insert_value_befor(arr, origin, value):
    print("insert value befor:", arr, origin, value)

    for key in range(len(arr)):
        if arr[key] == origin:
            break

    for index in range(len(arr) -1, key, -1):
        arr[index] = arr[index-1]

    arr[key] = value

    if key == len(arr):
        return arr, -1

    return arr, 0
    

def main():
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    index = find_val(arr, random.randint(1, 10))
    if index != -1:
        print("index:", index)


    arr = del_val(arr, random.randint(1, 10))
    print("del arr:", arr)

    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    arr, status = insert_value_befor(arr, random.randint(1, 9), random.randint(1, 10))
    if status == 0:
        print("insert:", arr)


if __name__ == "__main__":
    main()