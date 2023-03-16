#include "derivative.h"

float complex_derivative(float X, float deltaX) {
  return (cosf(X + deltaX) - cosf(X - deltaX)) / (2 * deltaX);
}
