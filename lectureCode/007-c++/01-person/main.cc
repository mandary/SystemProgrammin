#include <iostream>   // This is to C++ what <stdio.h> is to C
#include <cstdlib>    // To get a C system include file, like stdlib.h,
                      // prefix name with 'c' and drop the '.h'

#include "Person.h"

int main(int argc, char *argv[]) {
  // Unlike Java, an object isn't inherently a reference.
  // This allocates enough space on the stack for a complete
  // Address object.  It invokes the constructor to initialize
  // it.
  Address wh("16", "Pennsylvania Avenue", "Washington", "D.C.");
  Person fl("Michele", wh);
  std::cout << fl.toString() << std::endl;

  // Here's the creation of another Person.
  Person fd("Sunny", wh);
  std::cout << std::endl << fd->toString() << std::endl;

  return EXIT_SUCCESS;
}
