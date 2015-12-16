#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector_st {
  double x;
  double y;
} *Vector;

Vector vector_new(double initialX, double initialY);
void   vector_delete(Vector v);
char* vector_toString(const Vector v);

#endif // VECTOR_H
