#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"

class Circle {
public:
  static Circle get_circle(Point p, double r);
  void print();

private:
  Circle(Point p, double r);
  Point center;
  double radius;
};

#endif