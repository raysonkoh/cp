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

pair<long long, long long> extendEuclid(long long a, long long b) {  // returns {x,y}

  if (!b) return {1, 0};

  pair<long long, long long> p = extendEuclid(b, a % b);
  return {p.second, p.first - a / b * p.second};
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
  int t;
  cin >> t;
  while (t--) {
    long long a, n, b, m;
    cin >> a >> n >> b >> m;
    // m1n + m2m = 1
    auto [x, y] = extendEuclid(n, m);
    // cout << m1 << " " << m2 << endl;
    long long ans = a * y * m + b * x * n;
    long long k = n * m;
    while (ans < 0) {
      ans += k;
    }
    if (ans >= k) ans %= k;
    cout << ans << " " << k << '\n';
  }
}
