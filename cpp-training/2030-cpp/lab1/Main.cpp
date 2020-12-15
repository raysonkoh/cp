#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  Point pt(0.0, 0.0);
  pt.midpoint(Point(1.0, 1.0)).print();
  cout << pt.angleto(Point(1.0, 1.0)) << endl;
  cout << pt.angleto(Point(-1.0, -1.0)) << endl;

  pt.moveto(M_PI / 2.0, 1.0).print();

  Circle(pt, 1.0).print();

  return 0;
}
