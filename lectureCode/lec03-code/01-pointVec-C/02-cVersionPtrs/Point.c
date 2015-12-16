#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "Point.h"

Point point_new(double initialX, double initialY) {
  Point newPoint = (Point)malloc(1 * sizeof(struct point_st));
  if ( newPoint == NULL ) return NULL;
  newPoint->x = initialX;
  newPoint->y = initialY;
  return newPoint;
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
  p->x += v->x;
  p->y += v->y;
  return p;
}
