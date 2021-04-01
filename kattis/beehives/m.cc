#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

double dist(pair<double, double> p1, pair<double, double> p2) {
  auto [x, y] = p1;
  auto [xx, yy] = p2;

  return abs(x - xx) * abs(x - xx) + abs(y - yy) * abs(y - yy);
}

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double d;
  int n;
  while (cin >> d >> n) {
    if (d == 0.0 && n == 0) break;
    d *= d;
    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      v[i] = {x, y};
    }

    int sweet = 0;
    for (int i = 0; i < n; i++) {
      bool can = true;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;

        // cout << dist(v[i], v[j]) << endl;

        if (dist(v[i], v[j]) <= d) {
          can = false;
          break;
        }
      }
      if (can) {
        sweet++;
      }
    }

    cout << (n - sweet) << " sour, " << sweet << " sweet\n";
  }
}
