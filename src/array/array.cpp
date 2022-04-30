#include <assert.h>

#include <iostream>

const int INITIAL_CAPACITY = 2;
const int GROWTH_FACTOR = 2;

using namespace std;

class dynamicArray {
  char *array;
  int _size;
  int capacity = INITIAL_CAPACITY;

 public:
  dynamicArray() {
    array = new char[capacity];
    _size = 0;
  }

  ~dynamicArray() { delete[] array; }

  void deleteKey(int pos) {
    assert(0 < pos && pos < _size);
    _size--;
    for (int i = pos; i < _size; i++) {
      array[i] = array[i + 1];
    }
  }

  void insertKey(char element, int pos) {
    assert(0 < pos && pos < _size);
    if (_size == capacity) {
      resize();
    }

    for (int i = _size; i > pos; i--) {
      array[i] = array[i - 1];
    }
    _size++;
    array[pos] = element;
  }

  void resize() {
    capacity *= GROWTH_FACTOR;
    char *temp = new char[capacity];
    copy(array, array + _size, temp);
    delete[] array;
    array = temp;
  }

  void append(char element) { insertKey(element, _size); }

  int size() { return _size; }

  char get(int pos) { return array[pos]; }

  void pretty_print() {
    cout << "[";
    for (int i = 0; i < _size - 1; i++) {
      cout << array[i] << " ";
    }
    if (_size) {
      cout << array[_size - 1];
    }
    cout << "]";
  }
};

int main() {
  dynamicArray d;
  d.append(3);
  d.append(4);
  d.append(10);
  d.append(100);

  d.pretty_print();
  d.deleteKey(2);
  d.pretty_print();

  return 0;
}