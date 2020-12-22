#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double x1, y1, x2, y2, p;
  while (cin >> x1) {
    if (x1 == 0) {
      break;
    }
    cin >> y1 >> x2 >> y2 >> p;
    double res = pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1.0 / p);
    cout << fixed << setprecision(8) << res << endl;
  }
}
