#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>

// When you put the definition of a method in the .h file,
// you're allowing the compiler to inline the method (that is,
// basically to inject the code in at the call site, thus avoiding
// the overhead of a procedure call).  The compiler may, or may not,
// actually do the inlining.  (But, if you don't put the definition
// in the .h it for sure won't inline, because it can't.)

class Point {
 public:
  Point(const int x, const int y);  // constructor

  int get_x() const { return x_; }  // inline member function
  int get_y() const { return y_; }  // inline member function

  void SetLocation(const int x, const int y) {
    x_ = x;
    y_ = y;
  }  // inline member function

  double Distance(const Point &p) const;  // member function

 private:
  int x_;  // data member
  int y_;  // data member
};  // class Point


inline Point::Point(const int x, const int y) {
  x_ = x;
  this->y_ = y;  // this-> is optional, unless names conflict
}

inline double Point::Distance(const Point &p) const {
  // We can access p’s x_ and y_ variables either through the
  // get_x(), get_y() accessor functions, or the x_, y_ private
  // member variables directly, since we’re in a member function of
  // the same class.
  double distance = (x_ - p.get_x()) * (x_ - p.get_x());
  distance += (y_ - p.y_) * (y_ - p.y_);
  return sqrt(distance);
}

#endif  // _POINT_H_

