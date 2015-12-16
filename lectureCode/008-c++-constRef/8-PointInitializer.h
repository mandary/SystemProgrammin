#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>

class Point {
 public:
  // Rather than assigning to the member variables in the body
  // of the constructor, you can initialize them, like this:
  Point(const int x, const int y) : x_(x), y_(y) {}

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
  //------------------------------------------------------------------
  //const int &refExample;  // Just to show issue with a ref member
  //------------------------------------------------------------------
};  // class Point

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

