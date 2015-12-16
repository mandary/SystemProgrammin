#ifndef POINT_H
#define POINT_H

#include "Vector.h"

// Here we make private all instance variables of Points
// by not revealing them to client code.  Why does this work?
// In client code, all the client can do is copy and pass 
// around things of type Point.  The compiler knows Point is a
// pointer, so it knows how much space it takes (8 bytes).
// It knows how to do assignment -- copy the 8 bytes.
typedef struct point_st *Point;

// The initial fields in this vtable must match the 
// vtable fields of the parent class.  After that,
// we can add whatever new virtual functions are introduced
// by this class.
struct point_vtable_st {
  void  (*delete)(Point p);
  char *(*toString)(const Point p);
  Point (*addVector)(Point p, const Vector v);
};

typedef struct point_st {
  struct point_vtable_st *vtable;
  double x;
  double y;
} * Point;

// These methods are not virtual.
Point point_new(double initialX, double initialY);
void _point_constructor(Point p, double initialX, double initialY);

#endif // POINT_H
