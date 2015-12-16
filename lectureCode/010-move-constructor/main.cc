#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <cstdlib>
#include <cstring>

using namespace std;

#include "Example.h"

int main(int argc, char* argv[]) {

  //----------------------------------------------------
  // Aside: lvalues / rvalues
  //    Here's an odd example of an l-value expression
  int i=0, j=0;
  (argc < 2 ? i : j) = 10;
  cout << "i = " << i << " j = " << j << endl;
  //----------------------------------------------------

  cout << endl << "Construct ex" << endl;
  Example ex("main::ex");                    // String constructor
  cout << endl << "Construct mainResult" << endl;
  Example mainResult("main::mainResult");    // String constructor

  cout << endl << "Construct final" << endl;
  Example final(mainResult.exampleFunc(ex)); // copy constructor(copy constructor)

  // Assignment operator invocations
  // copy assign
  cout << endl << "Self-assignment statement:" << endl;
  mainResult = mainResult;  // We have to be careful to handle this case correctly

  // possible move assign
  cout << endl << "Function return assignment statement:" << endl;
  mainResult = mainResult.exampleFunc( mainResult );

  // print invocation count results
  cout << endl << Example::countString() << endl;
}
