#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Vector.h"

//-------------------------------------------------------
// Virtual method definitions
//-------------------------------------------------------

// Heads up: this isn't a very general implementation.
//   In C++ (which you don't need to know anything about yet)
//   the "destructor" for a class is executed and then
//   the destructor for the parent class is executed (on up to the root
//   class).  Here we "just know" that the parent class destructor
//   doesn't have anything to do.
static void _delete(Vector v) {
  free(v);
}

static char *_toString(const Vector v) {
  char *resultStr;
  asprintf( &resultStr, "Vector(%lf, %lf)", v->x, v->y );
  return resultStr;
}

static Vector _scale(Vector v, double scale) {
  v->x *= scale;
  v->y *= scale;
  v->length = sqrt(v->x*v->x + v->y*v->y);
  return v;
}

static double _length(const Vector v) {
  return v->length;
}

//-------------------------------------------------------
// Vector class's vable definition
//-------------------------------------------------------
static struct vector_vtable_st VECTOR_VTABLE = 
  { .delete = _delete,
    .toString = _toString,
    .scale = _scale,
    .length = _length
  };

//-------------------------------------------------------
// New instance support
//-------------------------------------------------------
void _vector_constructor(Vector v, double initialX, double initialY) {
  _tuple_constructor((Tuple)v);
  v->x = initialX;
  v->y = initialY;
  v->length = sqrt(v->x*v->x + v->y*v->y);
}

Vector vector_new(double initialX, double initialY) {
  Vector newVector = (Vector)malloc(1 * sizeof(struct vector_st));
  if ( newVector == NULL ) return NULL;
  newVector->vtable = &VECTOR_VTABLE;
  _vector_constructor(newVector, initialX, initialY);
  return newVector;
}

