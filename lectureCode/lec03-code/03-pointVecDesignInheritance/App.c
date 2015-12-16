#include <stdio.h>
#include "Point.h"
#include "Vector.h"

//----------------------------------------------
// This helper method is here for two reasons:
// 1. it shows that the code doesn't have to know
//    the type of the object to invoke the appropriate
//    implementation of toString on it, and
// 2. it lets us write the main code using a more
//    natural syntax to invoke toString (see the mainline)
//----------------------------------------------
static char *toString(Tuple t) {
  return t->vtable->toString(t);
}

//----------------------------------------------
// The mainline
//----------------------------------------------
int main(int argc, char *argv[]) {
  Point myPoint = point_new(0.0, 0.0);
  Vector unitX = vector_new(1.0, 0.0);
  Vector unitY = vector_new(0.0, 1.0);

  printf("%s + %s + %s = ", toString((Tuple)myPoint),
	                    toString((Tuple)unitX),
	                    toString((Tuple)unitY)
	);
  myPoint->vtable->addVector(myPoint, unitX);
  myPoint->vtable->addVector(myPoint, unitY);

  printf("%s\n", toString((Tuple)myPoint));

  myPoint->vtable->delete(myPoint);
  unitX->vtable->delete(unitX);
  unitY->vtable->delete(unitY);

  return 0;
}
