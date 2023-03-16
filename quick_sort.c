#include <stdio.h>

void _swap(int *array, int i, int j);
int partition(int *array, int min, int max, size_t size);
void quicksort(int *array, int min, int max, size_t size);
void quick_sort_hoare(int *array, size_t size);

int *quick_sort(int *array, int n) {
  quick_sort_hoare(array, n);
  return array;
}

void _swap(int *array, int i, int j) {
  int tmp;

  tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

int partition(int *array, int min, int max, size_t size) {
  int i, j, pivot = array[max];

  for (i = min, j = max; 1; i++, j--) {
    while (array[i] < pivot) i++;

    while (array[j] > pivot) j--;

    if (i >= j) return (i);
    _swap(array, i, j);
  }
}

void quicksort(int *array, int min, int max, size_t size) {
  int p;

  if (min < max) {
    p = partition(array, min, max, size);
    quicksort(array, min, p - 1, size);
    quicksort(array, p, max, size);
  }
}

void quick_sort_hoare(int *array, size_t size) {
  if (!array || size < 2) return;

  quicksort(array, 0, size - 1, size);
}