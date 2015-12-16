#include "func.h"

int main(int argc, char *argv[]);
static char *dummyArgv[] = { 0 };

// you can make a function's name have file scope
static void kindaPrivateFunc() {
  // can be called only from code that follows this definition in this file
}

void func() {
  kindaPrivateFunc();
  main(-1, dummyArgv);
}
