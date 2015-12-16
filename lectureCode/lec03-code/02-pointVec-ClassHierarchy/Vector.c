#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Vector.h"

static void _vector_setLength(Vector v) {
  v->length = sqrt(v->x*v->x + v->y*v->y);
}

Vector vector_new(double initialX, double initialY) {
  Vector v = (Vector)malloc(1 * sizeof(struct vector_st));
  if ( v == NULL ) return NULL;
  v->x = initialX;
  v->y = initialY;
  _vector_setLength(v);
  return v;
}

void vector_delete(Vector v) {
  free(v);
}

char *vector_toString(const Vector v) {
  char *resultStr;
  asprintf( &resultStr, "Vector(%lf, %lf)", v->x, v->y );
  return resultStr;
}

Vector vector_scale(Vector v, double size) {
  v->x *= size;
  v->y *= size;
  _vector_setLength(v);
  return v;
}

double vector_length(const Vector v) {
  return v->length;
}

