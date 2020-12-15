#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

class Circle {
public:
  Circle(Point p, double r);
  void print();

private:
  Point center;
  double rad;
};

#endif