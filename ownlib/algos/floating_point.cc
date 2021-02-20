#include <cmath>
#include <iostream>

using namespace std;

const double EPS = 1e-11;

bool greaterThan(double a, double b) {
  return a > b - EPS;
}

bool lesserThan(double a, double b) {
  return a < b + EPS;
}

bool isEqual(double a, double b) {
  return fabs(a - b) <= EPS;
}

int intCeil(int a, int b) {
  return (a + b - 1) / b;
}

int main() {
}