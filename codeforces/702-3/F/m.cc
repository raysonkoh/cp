#include <algorithm>
#include <cassert>
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
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<long long> s;
    map<long long, int> ctNum;  // (num, count of num)
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      s.insert(x);
      if (ctNum.count(x) == 0)
        ctNum[x] = 0;
      ctNum[x]++;
    }

    map<int, pair<int, int>> ct;  // (count, (num of elements with that count, distinct ele))
    for (auto [a, b] : ctNum) {
      if (ct.count(b) == 0)
        ct[b] = {0, 0};
      ct[b].first += b;
      ct[b].second++;
    }

    int res = 1e9;
    for (auto [candCt, p] : ct) {
      int tmp = 0;
      for (auto [a, b] : ct) {
        if (a == candCt) {
          continue;
        } else if (a < candCt) {
          tmp += b.first;
        } else {
          tmp += (a - candCt) * b.second;
        }
      }
      res = min(res, tmp);
    }

    cout << res << '\n';
  }
}
