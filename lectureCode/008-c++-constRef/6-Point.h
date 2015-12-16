#ifndef _POINT_H_
#define _POINT_H_

class Point {
 public:
  Point(const int x, const int y);  // constructor

  int get_x() const;                      // const member function
  int get_y() const;                      // const member function
  double Distance(const Point &p) const;  // const member function

  void SetLocation(const int x, const int y);  // non-const member function

 private:
  int x_;  // data member
  int y_;  // data member
};  // class Point

#endif  // _POINT_H_

