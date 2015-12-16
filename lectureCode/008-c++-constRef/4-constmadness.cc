#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
  int x = 5;          // x is an int
  const int y = 6;    // y is a (const int)
  y++;                // compiler error

  int const z = 6;    // identical to "const int z = 6;"
  z++;                // compiler error

  int const *w = &y;  // w is a (variable pointer) to a (const int)
  *w += 1;            // compiler error
  w++;                // ok

  int *const v = &x;   // v is a (const pointer) to a (variable int)
  *v += 1;             // ok
  v++;                 // compiler error

  int const *const u = &x;  // u is a (const pointer) to a (const int)
  *u += 1;                  // compiler error
  u++;                      // compiler error

  return EXIT_SUCCESS;
}
