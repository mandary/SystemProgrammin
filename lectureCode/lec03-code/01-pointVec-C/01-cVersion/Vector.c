#define _GNU_SOURCE
#include <stdio.h>

#include "Vector.h"

Vector vector_new(double initialX, double initialY) {
  Vector newVector = { .x = initialX, .y = initialY };
  return newVector;
}

char *vector_toString(Vector v) {
  char *resultStr;
  // not portable...
  asprintf( &resultStr, "Vector(%lf, %lf)", v.x, v.y );
  return resultStr;
}
