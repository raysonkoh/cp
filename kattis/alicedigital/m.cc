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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<long long> v(n);
    vector<bool> greaterThanM(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      greaterThanM[i] = (v[i] > m);
    }

    long long l = 0; // before m
    long long r = 0; // after m
    long long maxS = 0;
    bool containM = false;

    for (int i = 0; i < v.size(); i++) {
      if (v[i] == m) {
        if (containM) {
          maxS = max(maxS, l + r + m);
          containM = true;
          l = r;
          r = 0;
        } else {
          containM = true;
        }
      } else {
        if (greaterThanM[i]) {
          if (containM)
            r += v[i];
          else
            l += v[i];
        } else {
          if (containM) {
            maxS = max(maxS, l + r + m);
          }
          l = 0;
          r = 0;
          containM = false;
        }
      }
    }
    if (containM) {
      maxS = max(maxS, l + r + m);
    }

    cout << maxS << '\n';
  }
}