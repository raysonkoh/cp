#include <cfloat>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  double t;
  cin >> n >> t;
  vector<pair<double, double>> v(n);
  double minSpd;
  for (int i = 0; i < n; i++) {
    double d, s;
    cin >> d >> s;
    v[i] = make_pair(d, s);
    if (i == 0) {
      minSpd = s;
    } else {
      minSpd = min(minSpd, s);
    }
  }

  double lo = -minSpd;
  double hi = 1e18;
  while (hi - lo > 1e-9) {
    double m = lo + (hi - lo) / 2;
    double res = 0;
    for (auto &[d, s] : v) {
      res += d / (s + m);
    }

    if (res < t) {
      // c too large, move left
      hi = m;
    } else {
      // c too small, move right
      lo = m;
    }
  }
  cout << fixed << setprecision(8) << lo << endl;
}