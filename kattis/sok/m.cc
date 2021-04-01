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

tuple<bool, double, double> ok(double a, double b, double c, double i, double j, double k) {
  double unit = a / i;
  double maxb = unit * j;
  double maxc = unit * k;
  if (maxb > b || maxc > c) return {false, -1, -1};
  return {true, maxb, maxc};
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
  double a, b, c;
  cin >> a >> b >> c;
  double i, j, k;
  cin >> i >> j >> k;

  auto [aa, ab, ac] = ok(a, b, c, i, j, k);
  auto [bb, ba, bc] = ok(b, a, c, j, i, k);
  auto [cc, ca, cb] = ok(c, a, b, k, i, j);
  cout << fixed << setprecision(4);

  if (aa) {
    // cout << "first" << endl;
    cout << 0 << " " << b - ab << " " << c - ac << '\n';
  } else if (bb) {
    // cout << "second" << endl;
    cout << a - ba << " " << 0 << " " << c - bc << '\n';
  } else {
    // cout << "third" << endl;
    cout << a - ca << " " << b - cb << " " << 0 << '\n';
  }
}
