#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUCESS 0
#define ERROR -1
#define NOFOUND -2
#define EMPTY -3

int display_array(int arr[], int count) {
  if (count <= 0) {
    return ERROR;
  }

  for (int i = 0; i < count; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");

  return SUCESS;
}

int find_by_pos(int arr[], int count, int pos, int *res) {
  if (pos < 0 || pos >= count) {
    return ERROR;
  }

  *res = arr[pos];

  return SUCESS;
}

int find_by_val(int arr[], int count, int val, int *res) {
  if (count <= 0) {
    return ERROR;
  }

  for (int i = 0; i < count; i++) {
    if (val == arr[i]) {
      *res = i;
      return SUCESS;
    }
  }

  return NOFOUND;
}

int delete_by_pos(int arr[], int count, int pos) {
  if (pos < 0 || pos >= count || count <= 0) {
    return ERROR;
  }

  for (int i = pos; i < count - 1; i++) {
    arr[i] = arr[i + 1];
  }

  return SUCESS;
}

int delete_by_val(int arr[], int count, int val, int *res) {
  if (count <= 0) {
    return ERROR;
  }

  int delete_count = 0;
  for (int i = 0; i < count; i++) {
    if (val == arr[i]) {
      delete_count += 1;
    }

    if (delete_count) {
      arr[i] = arr[i + delete_count];
    }
  }

  if (!delete_count) {
    return NOFOUND;
  }
  *res = delete_count;

  return SUCESS;
}

int insert_by_pos(int arr[], int count, int pos, int data) {
  if (pos < 0 || pos >= count || count <= 0) {
    return ERROR;
  }

  for (int i = count; i > pos; i--) {
    arr[i] = arr[i - 1];
  }
  arr[pos] = data;

  return SUCESS;
}

int insert_by_value(int arr[], int count, int value, int data) {
  if (count <= 0) {
    return ERROR;
  }

  int i;
  for (i = 0; i < count; i++) {
    if (value == arr[i]) {
      break;
    }
  }

  if (i == count) {
    return NOFOUND;
  }

  for (int j = count; j > i; j--) {
    arr[j] = arr[j - 1];
  }
  arr[i] = data;

  return SUCESS;
}

int main(void) {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  srand((unsigned int)time(0));

  int pos = rand() % 9;
  int res;
  int ret = find_by_pos(arr, arr_size, pos, &res);
  if (SUCESS == ret) {
    printf("find by pos %d, value is %d\n", pos, res);
  } else {
    printf("find by pos error: %d\n", ret);
  }

  int value = rand() % 20;
  ret = find_by_val(arr, arr_size, value, &res);
  if (SUCESS == ret) {
    printf("find by value %d, pos is %d\n", value, res);
  } else {
    printf("find by value error: %d\n", ret);
  }

  display_array(arr, arr_size);

  pos = rand() % 9;
  int new_arr_size = arr_size;
  ret = delete_by_pos(arr, arr_size, pos);
  if (SUCESS == ret) {
    printf("delete by pos sucess: ");
    new_arr_size -= 1;
    display_array(arr, new_arr_size);
  } else {
    printf("delete by pos error: %d\n", ret);
  }

  value = rand() % 6 + 1;
  ret = delete_by_val(arr, new_arr_size, value, &res);
  if (SUCESS == ret) {
    printf("delete by value sucess: ");
    new_arr_size -= res;
    display_array(arr, new_arr_size);
  } else {
    printf("delete by value error: %d\n", ret);
  }

  if (new_arr_size < arr_size) {
    pos = rand() % 8;
    value = rand() % 100;
    ret = insert_by_pos(arr, new_arr_size, pos, value);
    if (SUCESS == ret) {
      printf("insert by pos sucess: ");
      new_arr_size += 1;
      display_array(arr, new_arr_size);
    } else {
      printf("insert by pos error: %d\n", ret);
    }
  }

  if (new_arr_size < arr_size) {
    value = rand() % 8;
    int data = rand() % 200;
    ret = insert_by_value(arr, new_arr_size, value, data);
    if (ret == SUCESS) {
      printf("insert by value sucess: ");
      new_arr_size += 1;
      display_array(arr, new_arr_size);
    } else {
      printf("insert by value error: %d\n", ret);
    }
  }

  return 0;
}
