#ifndef __DEF_H
#define __DEF_H

#include <string>

using std::string;

// This class has no explictly declared constructor.
// C++ will create a default constructor if one is needed
// (and you don't do any of many things, like declare any
// kind of constructor).
class Def {
 public:
  ~Def();

  string toString();

 private:
  int intVar;
  int *ptrVar;
  string strVar;
};

#endif // __DEF_H
