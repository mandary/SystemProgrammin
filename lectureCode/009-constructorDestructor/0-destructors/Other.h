#ifndef __OTHER_H
#define __OTHER_H

#include <string>

using namespace std;

class Other {
 public:
  Other(const string &strVal);
  ~Other();  // this is the destructor

  string toString();

 private:
  string strVal;
};

#endif // __OTHER_H
