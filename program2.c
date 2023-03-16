#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

const char DLIB_SORT[] = "./sort.so";
const char DLIB_DERIVATIVE[] = "./derivative.so";
const char DLIB_QUICK_SORT_FUNC[] = "quick_sort";
const char DLIB_BUBBLE_SORT_FUNC[] = "bubble_sort";
const char DLIB_SIMPLE_DERIVATIVE_FUNC[] = "simple_derivative";
const char DLIB_COMPLEX_DERIVATIVE_FUNC[] = "complex_derivative";

enum CMD { SWAP, FIRST, SECOND };
enum LIB { DERIVATIVE, SORT };

void sort_input_handler(int *(*func)(int *array, int n));
void derivative_input_handler(float (*func)(float X, float deltaX));

int main() {
  int cmd, library = DERIVATIVE;
  void *current_library_handler = dlopen(DLIB_DERIVATIVE, RTLD_NOW);
  if (!current_library_handler)
    fprintf(stderr, "dlopen failed: %s\n", dlerror());
  void *function_handler = NULL;
  while (1) {
    scanf("%d", &cmd);
    switch (cmd) {
      case SWAP:
        dlclose(current_library_handler);
        if (library == SORT) {
          current_library_handler = dlopen(DLIB_DERIVATIVE, RTLD_NOW);
          printf("Swapped to derivative.so\n");
        }
        if (library == DERIVATIVE) {
          current_library_handler = dlopen(DLIB_SORT, RTLD_NOW);
          printf("Swapped to sort.so\n");
        }
        library = 1 - library;
        break;
      case FIRST:
        if (library == SORT) {
          function_handler =
              dlsym(current_library_handler, DLIB_BUBBLE_SORT_FUNC);
          sort_input_handler(function_handler);
        }
        if (library == DERIVATIVE) {
          function_handler =
              dlsym(current_library_handler, DLIB_SIMPLE_DERIVATIVE_FUNC);
          derivative_input_handler(function_handler);
        }
        break;
      case SECOND:
        if (library == SORT) {
          function_handler =
              dlsym(current_library_handler, DLIB_QUICK_SORT_FUNC);
          sort_input_handler(function_handler);
        }
        if (library == DERIVATIVE) {
          function_handler =
              dlsym(current_library_handler, DLIB_COMPLEX_DERIVATIVE_FUNC);
          derivative_input_handler(function_handler);
        }
        break;
      default:
        printf("Unknown command\n");
    }
  }
  return 0;
}

void derivative_input_handler(float (*func)(float X, float deltaX)) {
  float X, deltaX;
  scanf("%f %f", &X, &deltaX);
  printf("%f", func(X, deltaX));
  putchar('\n');
}

void sort_input_handler(int *(*func)(int *array, int n)) {
  int n = 1, i;
  char c;
  int *array = malloc(sizeof(int) * n);
  while (scanf("%d", &i)) {
    printf("inputed [%d] at %d\n", i, n - 1);
    array[n - 1] = i;
    array = realloc(array, sizeof(int) * ++n);
    c = getchar();
    if (c == '\n') break;
  }
  array = func(array, n - 1);

  for (int i = 0; i < n - 1; ++i) printf("%d ", array[i]);
  putchar('\n');
}
