#include <iostream>
#include <cstdlib>

#include "Example.h"

using namespace std;

// We declared class variables in Example.h.  We also
// have to define them (which is what this is).
int Example::nMoveConstructors = 0;
int Example::nCopyConstructors = 0;
int Example::nMoveAssigns = 0;
int Example::nCopyAssigns = 0;

// String constructor
Example::Example(const char* str) { 
  cout << "String constructing " << str << endl;
  nameStr = strdup(str);
}

// Copy constructor
Example::Example(const Example &other) {
  string label("copy constructed ");
  label += std::to_string(nCopyConstructors);
  nameStr = strdup(label.c_str());
  nCopyConstructors++;
  cout << "Copy constructing from " << other.name() << " => " << name() << endl;
}

// Copy assignment operator
Example& Example::operator=(const Example &other) {
  cout << "Copy assignment from " << other.name() << " to " << name() << endl;
  nCopyAssigns++;
  // We have to be careful to handle self-assignments correctly:
  if ( &other == this ) return *this;
  if ( nameStr != nullptr ) free(nameStr);
  nameStr = strdup(other.nameStr);
  return *this;
}

// Destructor - must free any allocated space
Example::~Example() {
  cout << "Example destructor(" << name() << ")" << endl;
  free((void*)nameStr); // free() allows NULL
}

// Example function to see how args are passed and return values returned
//   Parameter object ex will need to be constructed.
Example Example::exampleFunc(const Example ex) {
  static int invocationCount = 0;
  string label("exampleFuncLocalAndReturn ");
  label += std::to_string(invocationCount++);
  Example result(label.c_str());  // String constructor
  return result;   // We're returning by value, so either copy or move constructor
}

//--------------------------------------------------------------------------------
#ifdef _USE_MOVE
// Move constructor -- the 'noexcept' can be needed to have the standard library
//   container classes use your move constructor
Example::Example(Example &&other) noexcept {
  cout << "Move constructing from " << other.name() << endl;
  nMoveConstructors++;
  // We steal ("move") the memory allocated by the other object, which is faster 
  // than creating a new copy of it.
  nameStr = other.nameStr;
  // We must leave the other object in a sensible state -- one on which the 
  // destructor can be run.
  other.nameStr = nullptr;
}

// Move assignment
Example& Example::operator=(Example &&other) noexcept {
  cout << "Move assignment: " << name() << " = " << other.name() << endl;
  nMoveAssigns++;
  // We have to be careful to handle self-assignments correctly:
  if ( &other == this ) return *this;
  if ( nameStr != nullptr ) free(nameStr);
  nameStr = other.nameStr;
  // We assign a literal to the other's name, for printing purposes.
  // Normally, we'd set other.nameStr to nullptr.
  other.nameStr = strdup("move assignment moved this name away");
  return *this;
}

#endif // _USE_MOVE
//--------------------------------------------------------------------------------

std::string Example::countString() {
  ostringstream result;
  result << "nMoveConstructors =  " << nMoveConstructors << endl;
  result << "nCopyConstructors = " << nCopyConstructors << endl;
  result << "nMoveAssigns = " << nMoveAssigns << endl;
  result << "nCopyAssigns = " << nCopyAssigns << endl;
  return result.str();
}

