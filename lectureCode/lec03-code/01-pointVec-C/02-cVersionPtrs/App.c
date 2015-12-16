#include <stdio.h>
#include "Point.h"
#include "Vector.h"

int main(int argc, char *argv[]) {
  Point myPoint = point_new(0.0, 0.0);
  Vector unitX = vector_new(1.0, 0.0);
  Vector unitY = vector_new(0.0, 1.0);

  printf("%s + %s + %s = ", point_toString(myPoint),
                            vector_toString(unitX),
                            vector_toString(unitY) );

  point_addVector(point_addVector(myPoint, unitX), unitY );

  printf("%s\n", point_toString(myPoint));

  point_delete(myPoint);
  vector_delete(unitX);
  vector_delete(unitY);

  return 0;
}
