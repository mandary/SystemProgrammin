#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

Vector vector_new(double initialX, double initialY) {
  Vector newVector = (Vector)malloc(1 * sizeof(struct vector_st));
  if ( newVector == NULL ) return NULL;
  newVector->x = initialX;
  newVector->y = initialY;
  return newVector;
}

void vector_delete(Vector v) {
  free(v);
}

char *vector_toString(const Vector v) {
  char *resultStr;
  asprintf( &resultStr, "Vector(%lf, %lf)", v->x, v->y );
  return resultStr;
}
