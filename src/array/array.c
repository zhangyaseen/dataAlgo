#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR -1
#define NOFOUND -2
#define EMPTY -3

int find_val(int[], int, int);
int del_val(int[], int, int);
int insert_val_befor(int[], int, int, int);
int insert_val_after(int[], int, int, int);

int main(void) {
  int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  srand((unsigned int)time(0));
  int ret = find_val(arr, arr_size, rand() % 20);
  if (ERROR == ret) {
    printf("array is empty\n");
  } else if (NOFOUND == ret) {
    printf("key is not found\n");
  } else {
    printf("the key is :%d\n", ret);
  }

  int ret_count = del_val(arr, arr_size, rand() % 6 + 1);
  if (ERROR == ret_count) {
    printf("array is error\n");
  } else if (NOFOUND == ret_count) {
    printf("val not found\n");
  } else {
    for (int i = 0; i < arr_size - ret_count; i++) {
      printf("%d\t", arr[i]);
    }
    printf("\n");
  }

  int stauts = insert_val_befor(arr, arr_size, rand() % 6 + 1, rand() % 10 + 5);
  if (ERROR == stauts || NOFOUND == stauts) {
    printf("array insert is error\n");
  } else {
    for (int i = 0; i < arr_size + 1; i++) {
      printf("%d\t", arr[i]);
    }
    printf("\n");
  }

  stauts = insert_val_after(arr, arr_size, rand() % 6 + 1, rand() % 10 + 5);
  if (ERROR == stauts || NOFOUND == stauts) {
    printf("array is error\n");
  } else {
    for (int i = 0; i < arr_size + 1; i++) {
      printf("%d\t", arr[i]);
    }
    printf("\n");
  }

  return 0;
}

// array is not full
int insert_val_after(int arr[], int count, int val, int new_val) {
  if (count < 0) {
    return ERROR;
  }

  printf("origin key: %d, insert val: %d\n", val, new_val);

  int i;
  int val_index;
  for (i = 0; i < count; i++) {
    if (val == arr[i]) {
      val_index = i;
      break;
    }
  }

  for (int j = count - 1; j > val_index - 1; j--) {
    arr[j] = arr[j - 1];
  }

  if (i == count) {
    return -2;
  } else {
    arr[val_index] = new_val;
  }

  return 0;
}

// array is not full
int insert_val_befor(int arr[], int count, int val, int new_val) {
  if (count < 0) {
    return ERROR;
  }

  printf("origin key: %d, insert val: %d\n", val, new_val);

  int val_index, i;
  for (int i = 0; i < count; i++) {
    if (val == arr[i]) {
      val_index = i;
      break;
    }
  }

  for (int j = count - 1; j > val_index; j--) {
    arr[j] = arr[j - 1];
  }

  if (val_index == count) {
    return NOFOUND;
  } else {
    arr[val_index] = new_val;
  }

  return 0;
}

int del_val(int arr[], int count, int val) {
  if (count <= 0) {
    return ERROR;
  }
  int del_count = 0;

  printf("del val: %d\n", val);
  for (int i = 0; i < count; i++) {
    if (val == arr[i]) {
      del_count += 1;
    }
    if (del_count > 0) {
      arr[i] = arr[i + del_count];
    }
  }

  if (0 == del_count) {
    return NOFOUND;
  }

  return del_count;
}

int find_val(int arr[], int count, int val) {
  if (count <= 0) {
    return ERROR;
  }

  printf("finding val: %d\n", val);
  for (int i = 0; i < count; i++) {
    if (val == arr[i]) {
      return i;
    }
  }

  return NOFOUND;
}
