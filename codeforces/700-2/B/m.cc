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
#include <stack>
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
    long long A, B;
    int n;
    cin >> A >> B >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> v[i].second;
    }

    sort(v.begin(), v.end());

    bool can = true;
    for (int i = 0; i < n; i++) {
      long long numAttacks = ceil((double)v[i].second / (double)A);
      long long attack = numAttacks * v[i].first;

      B -= attack;
      if ((i != n - 1 && B < 1) || (i == n - 1 && B + v[i].first < 1)) {
        can = false;
      }

      if (!can)
        break;
    }

    cout << (can ? "YES" : "NO") << '\n';
  }
}
