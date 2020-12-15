#include "Point.h"
#include <cmath>
#include <iostream>

using namespace std;

Point::Point() {
  x = -1;
  y = -1;
}

Point::Point(double a, double b) {
  x = a;
  y = b;
}

Point Point::midpoint(Point p) {
  double newx = (x + p.x) / 2.0;
  double newy = (y + p.y) / 2.0;
  return Point(newx, newy);
}

double Point::angleto(Point p) {
  double xoffset = p.x - x;
  double yoffset = p.y - y;
  return atan2(yoffset, xoffset);
}

Point Point::moveto(double angle, double dist) {
  double newx = x + dist * cos(angle);
  double newy = y + dist * sin(angle);
  return Point(newx, newy);
}

void Point::print() { cout << "(" << x << ", " << y << ")" << endl; }
