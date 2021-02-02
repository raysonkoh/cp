#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  double a = 123.1150;
  cout << fixed << setprecision(2) << a << endl;
}