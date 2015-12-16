#define _GNU_SOURCE
#include <stdio.h>

#include "Point.h"

Point point_new(double initialX, double initialY) {
  Point newPoint = { .x = initialX, .y = initialY };
  return newPoint;
}

char *point_toString(Point p) {
  char *resultStr;
  // not portable
  asprintf( &resultStr, "Point(%lf, %lf)", p.x, p.y );
  return resultStr;
}

Point point_addVector(Point *p, Vector v) {
  p->x += v.x;
  p->y += v.y;
  return *p;
}
