#include <stdio.h>

void _swap(int *array, int i, int j) {
  int tmp;

  tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

int *bubble_sort(int *array, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (array[i] > array[j]) {
        _swap(array, i, j);
      }
    }
  }
  return array;
}