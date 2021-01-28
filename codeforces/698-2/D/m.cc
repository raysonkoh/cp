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
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    long long g = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++) {
      g = gcd(g, v[i + 1] - v[i]);
    }
    bool can = false;
    for (long long x : v) {
      if (abs(x - k) % g == 0) {
        can = true;
        cout << "YES\n";
        break;
      }
    }
    if (!can)
      cout << "NO\n";
  }
}
