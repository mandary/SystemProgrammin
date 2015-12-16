#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "Point.h"

//--------------------------------------------------------
// Virtual function definitions.
//--------------------------------------------------------
static void _delete(Point p) {
  free(p);
}

static char *_toString(const Point p) {
  char *resultStr;
  asprintf( &resultStr, "Point(%lf, %lf)", p->x, p->y );
  return resultStr;
}

static Point _addVector(Point p, const Vector v) {
  return (Point)_tuple_add((Tuple)p, (const Tuple)v);
}

//--------------------------------------------------------
// Point class's vtable
//--------------------------------------------------------
static struct point_vtable_st POINT_CLASS_VTABLE =
  { .delete = _delete,
    .toString = _toString,
    .addVector = _addVector
  };

//--------------------------------------------------------
// "new" -- memory allocation and initialization routines
//--------------------------------------------------------
void _point_constructor(Point p, double initialX, double initialY) {
  _tuple_constructor((Tuple)p);  // Note that I statically know the name of my parent class
  p->x = initialX;
  p->y = initialY;
}

Point point_new(double initialX, double initialY) {
  Point p = (Point)malloc(1 * sizeof(*p));
  if ( p == NULL ) return NULL;
  p->vtable = &POINT_CLASS_VTABLE;
  _point_constructor(p, initialX, initialY);
  return p;
}

