#ifndef POINT_H
#define POINT_H

class Point {
public:
  Point(double a, double b);
  Point mid_point(Point p);
  double angle_to(Point p);
  Point move_to(double angle, double dist);
  void print();

private:
  double x, y;
};

#endif