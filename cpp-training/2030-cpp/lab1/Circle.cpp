#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(Point p, double r) {
  center = p;
  rad = r;
}

void Circle::print() {
  cout << "center: ";
  center.print();
  cout << "rad: " << rad << endl;
}
