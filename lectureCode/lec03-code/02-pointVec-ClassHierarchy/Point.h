#ifndef POINT_H
#define POINT_H

#include "Vector.h"

// It's important that we remember to make the initial
// portion of this struct identical to the Tuple struct,
// if we want to be able to pass a Point where a Tuple
// is expected (i.e., to have subclassing).
typedef struct point_st {
  double x;
  double y;
} * Point;

Point point_new(double initialX, double initialY);
void  point_delete(Point p);
char *point_toString(const Point p);
Point point_addVector(Point p, const Vector v);

#endif // POINT_H
