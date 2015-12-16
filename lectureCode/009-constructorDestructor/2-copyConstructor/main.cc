#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Example.h"

using namespace std;

Example sub(Example ex) {
  return ex;
}

int main(int argc, char* argv[]) {
  const string prompt = "\n===> ";

  Example local("local");
  Example *pExample = new Example("new'ed object");
  Example local_clone(local);

  cout << prompt << "Call sub() then initialize" << endl;
  Example returnedVal = sub(local);
  cout << "returnedVal = " << returnedVal.toString() << endl;

  cout << prompt << "Call sub() then assign" << endl;
  returnedVal = sub(local_clone);

  cout << prompt << "Evaluate expression" << endl;
  Example concat = local + *pExample + local_clone + returnedVal;

  cout << prompt << "delete pExample" << endl;
  delete pExample;

  cout << prompt << "return from main" << endl;
  return 0;
}
