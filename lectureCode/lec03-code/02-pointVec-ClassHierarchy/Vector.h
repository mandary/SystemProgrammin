#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"

// It's important that this struct start with the instance
// variables of the parent class, Tuple.  After that, we
// can add any additional instance variables we want.
typedef struct vector_st {
  double x;
  double y;
  double length;
} *Vector;

Vector vector_new(double initialX, double initialY);
void   vector_delete(Vector v);
char  *vector_toString(const Vector v);
Vector vector_scale(Vector v, double size);  // changes length of the vector
double vector_length(const Vector v);        // returns the length of the vector

#endif // VECTOR_H
