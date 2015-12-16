#include <iostream>

#include <cstdio>

#include "exampleClass.h"

int main(int argc, char *argv[]) {
  ExampleClass alice("alice", 10.0, 20.0);

  std::cout << "Alice's weight: " << alice.getWeight() << std::endl;

  return 0;
}
