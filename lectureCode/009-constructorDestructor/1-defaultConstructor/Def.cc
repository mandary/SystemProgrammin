#include <iostream>
#include <sstream>

#include "Def.h"

using namespace std;

Def::~Def() {
  cout << "Def destructor: " << toString() << endl;
}

string Def::toString() {
  ostringstream result;
  result << "<intVar: " << intVar
	 << " ptrVar: " << ptrVar
	 << " strVar: '" << strVar << "'>";
  return result.str();
}
