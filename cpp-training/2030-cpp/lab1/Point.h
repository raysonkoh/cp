#ifndef POINT_H
#define POINT_H

class Point {
public:
  Point();
  Point(double a, double b);
  Point midpoint(Point p);
  double angleto(Point p);
  Point moveto(double angle, double dist);
  void print();

private:
  double x, y;
};

#endif