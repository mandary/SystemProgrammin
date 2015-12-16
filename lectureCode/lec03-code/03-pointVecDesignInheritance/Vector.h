#ifndef VECTOR_H
#define VECTOR_H

// The Vector class is a direct child of the Tuple class
#include "Tuple.h"

// You can define a type that is a pointer to something whose
// definition isn't available yet.  (How can that be?)
typedef struct vector_st *Vector;

// A vtable contains pointers to the virtual functions of the class.
// (Everything but the constructor is virtual in this example.)
// The initial entries must match those in the superclass (Tuple).
struct vector_vtable_st {
  void   (*delete)(Vector v);
  char  *(*toString)(const Vector v);
  Vector (*scale)(Vector v, double size);
  double (*length)(const Vector v);
};

// Note that the initial portion of this structure matches 
// the Tuple struture.
typedef struct vector_st {
  struct vector_vtable_st *vtable;
  double x;
  double y;
  double length;
} *Vector;

Vector vector_new(double initialX, double initialY);
void _vector_constructor(Vector v, double initialX, double initialY);

#endif // VECTOR_H
