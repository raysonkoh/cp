#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double d, v;
  while (cin >> d >> v) {
    if (d == 0 && v == 0)
      break;

    double res = ((2.0 / 3.0) * d * d * d - ((4.0 * v) / M_PI)) / (2.0 / 3.0);
    cout << fixed << setprecision(8) << pow(res, 1.0 / 3.0) << '\n';
  }
}