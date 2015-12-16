#include <iostream>
#include <cstdlib>

void BrokenPrintSquare(const int &i) {
  i = i*i;  // Compiler error here.
  std::cout << i << std::endl;
}

int main(int argc, char **argv) {
  int j = 2;

  BrokenPrintSquare(j);

  std::cout << "j = " << j << std::endl;
  return EXIT_SUCCESS;
}
