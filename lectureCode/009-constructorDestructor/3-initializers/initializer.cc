#include <iostream>
#include <cstring>

using namespace std;

class MyClass {
private:
  char * str;
public:
  MyClass(const char *s) {
    cout << "String constructor: " << s << endl;
    str = strdup(s);
  }
  ~MyClass() {
    free(str);
  }

  MyClass(const MyClass &other) {
    cout << "Copy constructor: " << other.str << endl;
    str = strdup(other.str);
  }

  const char *toString() {
    return str;
  }
};

int main(int argc, char *argv[]) {
  MyClass mc0("direct initialization");
  MyClass mc1 = "copy initialization";
  MyClass mc2 = {"list initialization"};
  MyClass mc3{"another direct initialization"};

  cout << endl << "Output from main:" << endl;
  cout << mc0.toString() << endl
       << mc1.toString() << endl
       << mc2.toString() << endl
       << mc3.toString() << endl;

  return 0;
}
