#ifndef POINT_H
#define POINT_H

#include "Vector.h"

typedef struct point_st {
  double x;
  double y;
} Point;

Point point_new(double initialX, double initialY);
char *point_toString(Point p);
Point point_addVector(Point *p, Vector v);

#endif // POINT_H
