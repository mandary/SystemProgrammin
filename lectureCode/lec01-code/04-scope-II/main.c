#include <stdio.h>

#include "func.h"

// An ordinary global
int globalVar = 12345;

// Declares a global name, otherGlobal, but says it's defined in some
// other file
extern int otherGlobal;

// Declares a variable that is allocated in the static data area
//  but the variable's name has file scope (i.e., this file only).
static int fileScopeVar = 2;

// All function names are global (including 'main')
// Argument names have scope of the method body
int main(int argc, char *argv[]) {

  // variables declared within methods have local scope.
  int localVar = 1;

  // it's possible to allocate a variable in the static data area
  // but make its name have local scope
  static int staticLocal = 0;

  staticLocal += fileScopeVar - localVar;

  if ( argc < 0 ) return 0;

  kindaPrivateFunc();
  func();

  printf ("staticLocal = %d\n", staticLocal);

  return 0;
}
