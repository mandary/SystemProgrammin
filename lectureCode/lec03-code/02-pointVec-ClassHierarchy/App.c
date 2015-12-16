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

  point_addVector(myPoint, unitX);
  point_addVector(myPoint, unitY);

  printf("As a tuple: %s\n", tuple_toString((Tuple)myPoint));
  printf("As a point: %s\n", point_toString(myPoint));

  printf( "After scaling unitX by -0.5: %s\n",
	  vector_toString(vector_scale(unitX, -0.5))
	);
  printf("unitX has length %lf\n", vector_length(unitX));

  vector_delete(unitX);
  vector_delete(unitY);
  point_delete(myPoint);

  return 0;
}
