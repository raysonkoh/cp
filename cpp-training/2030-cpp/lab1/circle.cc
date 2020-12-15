#include "circle.h"
#include "point.h"
#include <iostream>

Circle Circle::get_circle(Point p, double r) {
  if (r <= 0) {
    std::cout << "error" << std::endl;
    return Circle(Point(-1, -1), -1);
  }
  return Circle(p, r);
}

void Circle::print() {
  std::cout << "circle of radius " << radius << " centered at ";
  center.print();
}

Circle::Circle(Point p, double r) : center(p), radius(r) {}
