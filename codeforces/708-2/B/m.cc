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

int findMaxPartners(int x, int m, multiset<int> s) {
  int other = (m - x) % m;
  s.erase(s.find(x));
  int res = 1;
  while (s.count(other) > 0) {
    res++;
    x = other;
    other = (m - x) % m;
    s.erase(s.find(x));
  }
  return res;
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
    int n, m;
    cin >> n >> m;
    map<int, int> ct;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int r = x % m;
      if (ct.count(r) == 0)
        ct[r] = 0;
      ct[r]++;
    }

    int res = 0;
    while (ct.size() > 0) {
      auto [x, ctX] = *ct.begin();
      // cout << "x: " << x << " ctX: " << ctX << endl;
      int other = (m - x) % m;
      if (ct.count(other) == 0) {
        res += ctX;
      } else {
        int ctOther = ct[other];
        // cout << "other: " << other << " ctOther: " << ctOther << endl;
        if (ctOther > ctX) {
          res += 1 + max(0, (ctOther - ctX - 1));
        } else {
          res += 1 + max(0, (ctX - ctOther - 1));
        }
        ct.erase(other);
      }
      ct.erase(x);
    }
    cout << res << '\n';
  }
}
