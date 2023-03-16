#include <stdio.h>

#include "derivative.h"

enum CMD { SIMPLE = 1, COMPLEX };

void derivative_input_handler(float (*func)(float X, float deltaX));

int main() {
  int cmd;
  while (1) {
    scanf("%d", &cmd);
    switch (cmd) {
      case SIMPLE:
        derivative_input_handler(simple_derivative);
        break;
      case COMPLEX:
        derivative_input_handler(complex_derivative);
        break;
      default:
        break;
    }
  }

  return 0;
}

void derivative_input_handler(float (*func)(float X, float deltaX)) {
  float X, deltaX;
  scanf("%f %f", &X, &deltaX);
  printf("%f", func(X, deltaX));
}
