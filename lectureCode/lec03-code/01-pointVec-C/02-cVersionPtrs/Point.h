#ifndef POINT_H
#define POINT_H

#include "Vector.h"

typedef struct point_st {
  double x;
  double y;
} * Point;

Point point_new(double initialX, double initialY);
void  point_delete(Point p);
char *point_toString(const Point p);
Point point_addVector(Point p, const Vector v);

#endif // POINT_H
