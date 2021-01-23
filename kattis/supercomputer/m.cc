#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

class BIT {
public:
  vector<long long> v;
  BIT(int n) { v.assign(n + 1, 0); }

  void update(int x, long long delta) {
    for (; x < v.size(); x += LSOne(x)) {
      v[x] += delta;
    }
  }

  long long prefixSum(int x) {
    long long res = 0;
    for (; x; x -= LSOne(x)) {
      res += v[x];
    }
    return res;
  }

  long long sumRange(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1, 0);
  BIT bit(n);
  while (k--) {
    char cmd;
    cin >> cmd;
    if (cmd == 'F') {
      int x;
      cin >> x;
      if (v[x]) {
        bit.update(x, -1);
        v[x] = 0;
      } else {
        bit.update(x, 1);
        v[x] = 1;
      }
    } else {
      // query
      int l, r;
      cin >> l >> r;
      cout << bit.sumRange(l, r) << '\n';
    }
  }
}