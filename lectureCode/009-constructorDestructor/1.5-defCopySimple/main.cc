#include "MyClass.h"

MyClass sub(MyClass arg) {
  return arg;
}

int main(int argc, char* argv[]) {
  MyClass a;
  MyClass b("b");
  MyClass c(b);

  sub(c);
}
