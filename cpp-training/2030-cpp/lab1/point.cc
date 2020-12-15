#include "point.h"
#include <cmath>
#include <iomanip>
#include <iostream>

Point::Point(double a, double b) : x(a), y(b) {}

void Point::print() {
  std::cout << std::fixed << std::setprecision(3) << "point (" << x << ", " << y
            << ")" << std::endl;
}

Point Point::mid_point(Point p) {
  double newx = (x + p.x) / 2.0;
  double newy = (y + p.y) / 2.0;
  return Point(newx, newy);
}

double Point::angle_to(Point p) {
  double offx = p.x - x;
  double offy = p.y - y;
  return atan2(offy, offx);
}

Point Point::move_to(double angle, double dist) {
  double newx = x + dist * cos(angle);
  double newy = y + dist * sin(angle);
  return Point(newx, newy);
}
