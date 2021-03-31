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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<string, set<string>> m;
    for (int i = 0; i < n; i++) {
      string s1, s2;
      cin >> s1 >> s2;
      if (m.count(s2) == 0) {
        m[s2] = set<string>();
      }
      m[s2].insert(s1);
    }

    int ans = 1;
    for (auto [st, sts] : m) {
      ans *= (sts.size() + 1);
    }
    cout << ans - 1 << '\n';
  }
}
