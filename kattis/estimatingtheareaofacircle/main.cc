#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double r, m, c;
  while (cin >> r >> m >> c) {
    if (r == 0 && m == 0 && c == 0) {
      break;
    }
    double trueArea = M_PI * r * r;
    double estimate = (2 * r * 2 * r) * (c / m);
    cout << fixed << setprecision(6) << trueArea << " " << estimate << endl;
  }
}