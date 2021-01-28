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
    cin >> n;
    set<long long> seen;
    vector<long long> v;
    for (int i = 0; i < 2 * n; i++) {
      long long x;
      cin >> x;
      if (seen.count(x) == 0) {
        seen.insert(x);
        v.push_back(x);
      }
    }

    sort(v.rbegin(), v.rend());
    if (v.size() != n) {
      cout << "NO\n";
      continue;
    }

    long long offset = 0;
    bool can = true;
    for (int i = 0; i < n; i++) {
      v[i] -= offset;
      if (v[i] <= 0 || v[i] % (long long)(2 * (n - i)) != 0) {
        can = false;
        break;
      }

      long long a = v[i] / (long long)(2 * (n - i));
      if (a <= 0) {
        can = false;
        break;
      }
      // cout << a << endl;
      offset += 2 * a;
    }
    cout << (can ? "YES\n" : "NO\n");
  }
}
