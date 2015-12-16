#ifndef __MYCLASS_H
#define __MYCLASS_H

#include <string>

using std::string;

class MyClass {
 public:
  /*
    // ------- "some constructor" ------- 
    MyClass(std::string s) {
      strVar = s;
    }    
  */
  
  /*
    // ------- "default constructor" ------- 
    MyClass() {
      // is this equivalent to the default default constructor?
    }
  */

  /*
    //  ------- !! ------- 
    MyClass() = default;
  */

  /*
    //  ------- !! ------- 
    MyClass() = delete;
  */

  /*
    // ------- "copy constructor" ------- 
    MyClass(MyClass &other) {
      std::cout << "Copy constructor: '" << other.toString() << "'" << std::endl;
   }
  */
  
  const std::string& toString();

 private:
  std::string strVar;
};

#endif // __MYCLASS_H
