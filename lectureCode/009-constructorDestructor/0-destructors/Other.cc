#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#include "Other.h"

using namespace std;

Other::Other(const string &strVal) {
  cout << "Other constructor(" << strVal << ")" << endl;
  this->strVal = strVal;
}

Other::~Other() {
  cout << "   Other destructor(" << toString() << ")" << endl;
}

string Other::toString() {
  ostringstream result;
  result << "{strVal = '" << strVal << "'}";
  return result.str();
}
