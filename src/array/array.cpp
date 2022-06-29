#include <assert.h>

#include <iostream>

const int INITIAL_CAPACITY = 2;
const int GROWTH_FACTOR = 2;

using namespace std;

class dynamicArray {
public:
  dynamicArray() {
    array = new int[capacity];
    _size = 0;
  }

  ~dynamicArray() { delete[] array; }

  char get(int pos) {
    assert(0 <= pos && pos < _size);
    return array[pos];
  }

  void resize() {
    capacity *= GROWTH_FACTOR;
    int *temp = new int[capacity];
    copy(array, array + _size * sizeof(int), temp);
    delete[] array;
    array = temp;
  }

  void insertByPos(char element, int pos) {
    assert(0 <= pos && pos <= _size);
    if (_size == capacity) {
      resize();
    }

    for (int i = _size; i > pos; i--) {
      array[i] = array[i - 1];
    }
    _size++;
    array[pos] = element;
  }

  void deleteByPos(int pos) {
    assert(0 <= pos && pos < _size);
    _size--;
    for (int i = pos; i < _size; i++) {
      array[i] = array[i + 1];
    }
  }

  void append(char element) { insertByPos(element, _size); }

  int size() { return _size; }

  void display() {
    cout << "[";
    for (int i = 0; i < _size - 1; i++) {
      cout << array[i] << " ";
    }
    if (_size) {
      cout << array[_size - 1];
    }
    cout << "]" << endl;
  }

private:
  int *array;
  int _size;
  int capacity = INITIAL_CAPACITY;
};

int main() {
  dynamicArray d;
  d.display();
  d.append(3);
  d.append(4);
  d.append(10);
  d.append(100);

  d.display();
  d.deleteByPos(2);
  d.display();

  return 0;
}