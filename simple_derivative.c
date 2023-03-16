#include "derivative.h"

float simple_derivative(float X, float deltaX) {
  return (cosf(X + deltaX) - cosf(X)) / deltaX;
}