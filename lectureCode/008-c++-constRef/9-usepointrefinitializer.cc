#include <iostream>
#include "9-PointRefInitializer.h"

using namespace std;

int main(int argc, char **argv){
  Point p1(1, 2);
  Point p2(4, 6);

  cout << "p1 is: (" << p1.get_x() << ", "
       << p1.get_y() << ")" << endl;

  cout << "p2 is: (" << p2.get_x() << ", "
       << p2.get_y() << ")" << endl;

  cout << "dist : " << p1.Distance(p2) << endl;
  return 0;
}
