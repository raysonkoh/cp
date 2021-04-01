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
  double x, y;
  cin >> x >> y;
  int n;
  cin >> n;
  vector<tuple<double, double, double>> sch(n);
  for (int i = 0; i < n; i++) {
    double l, u, f;
    cin >> l >> u >> f;
    sch[i] = {l, u, f};
  }
  sort(sch.begin(), sch.end());

  double cury = 0;
  double time = 0;
  for (auto [l, u, f] : sch) {
    time += l - cury;
    time += (u - l) * f;
    cury = u;
  }

  time += y - cury;

  cout << fixed << setprecision(8) << x / time << '\n';
}
