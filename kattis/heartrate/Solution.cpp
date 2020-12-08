#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    double b, p;
    cin >> b >> p;
    double a1 = 60.0 * b / p - (60.0 / p);
    double a2 = 60.0 * b / p;
    double a3 = 60.0 * b / p + (60.0 / p);
    cout << fixed << setprecision(8) << a1 << " " << a2 << " " << a3 << endl;
  }
  return 0;
}