#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  double r;
  cin >> r;
  cout << fixed << setprecision(6);
  cout << M_PI * r * r << endl;
  cout << r * r * 2 << endl;
}