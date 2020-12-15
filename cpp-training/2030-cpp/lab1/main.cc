#include "circle.h"
#include "point.h"
#include <cmath>
#include <iostream>

int main() {
  Point p(0.0, 0.0);

  p.mid_point(Point(1.0, 1.0)).print();
  std::cout << p.angle_to(Point(1.0, 1.0)) << std::endl;
  std::cout << p.angle_to(Point(-1.0, -1.0)) << std::endl;

  p.move_to(M_PI / 2.0, 1.0).print();

  // Circle(p, 1.0);
  Circle::get_circle(p, 1.0).print();
  Circle::get_circle(p, -1.0).print();
  Circle::get_circle(p, 0.0).print();
}
