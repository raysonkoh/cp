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
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double lo, hi;
  while (cin >> lo >> hi) {
    int n;
    cin >> n;
    vector<tuple<double, double, int>> v(n);
    for (int i = 0; i < n; i++) {
      double st, ed;
      cin >> st >> ed;
      v[i] = {st, ed, i};
    }
    sort(v.begin(), v.end(), [](tuple<double, double, int> t1, tuple<double, double, int> t2) {
      auto [a1, b1, c1] = t1;
      auto [a2, b2, c2] = t2;
      if (fabs(a1 - a2) > EPS) {
        return a1 < a2;
      }
      return b1 > b2;
    });
    double maxSoFar = lo;
    vector<int> res;
    bool can = true;
    for (int i = 0; i < n; i++) {
      if (res.size() > 0 && maxSoFar >= hi - EPS) break;
      auto [a, b, c] = v[i];
      // cout << "a: " << a << " b: " << b << " c: " << c << endl;
      if (res.size() > 0 && b < maxSoFar + EPS) continue;
      if (a < maxSoFar + EPS) {  // can cover
        double maxR = b;
        int jump = i;
        int maxId = c;
        for (int j = i + 1; j < n && get<0>(v[j]) < maxSoFar + EPS; j++) {
          // cout << get<0>(v[j]) << " " << get<1>(v[j]) << " " << j << endl;
          if (get<1>(v[j]) > maxR) {
            maxR = get<1>(v[j]);
            maxId = get<2>(v[j]);
            jump = j;
          }
        }
        res.push_back(maxId);
        maxSoFar = maxR;
        // cout << "maxsofar: " << maxSoFar << " maxR: " << maxR << " maxId: " << maxId << endl;
        i = jump;
      } else {
        // cout << "a: " << a << " maxSOFar: " << maxSoFar << endl;
        can = false;
        break;
      }
    }

    can = can && res.size() > 0 && (maxSoFar >= hi - EPS);
    if (!can)
      cout << "impossible\n";
    else {
      cout << res.size() << '\n';
      bool isFirst = true;
      for (auto x : res) {
        if (isFirst)
          isFirst = false;
        else
          cout << " ";
        cout << x;
      }
      cout << '\n';
    }
  }
}
