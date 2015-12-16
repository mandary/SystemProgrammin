#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "Point.h"

Point point_new(double initialX, double initialY) {
  Point p = (Point)malloc(1 * sizeof(*p));
  if ( p == NULL ) return NULL;
  p->x = initialX;
  p->y = initialY;
  return p;
}

void point_delete(Point p) {
  free(p);
}

char *point_toString(const Point p) {
  char *resultStr;
  asprintf( &resultStr, "Point(%lf, %lf)", p->x, p->y );
  return resultStr;
}

Point point_addVector(Point p, const Vector v) {
  return (Point)_tuple_add((Tuple)p, (Tuple)v);
}

