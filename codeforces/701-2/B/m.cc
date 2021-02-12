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
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> v(n + 2);
  v[0] = 0;
  v[n + 1] = k + 1;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  vector<int> offset(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int lo = v[i - 1];
    int hi = v[i + 1];
    offset[i] = max(hi - lo - 2, 0);
  }

  /*
  for (auto x : offset)
    cout << x << " ";
  cout << endl;
  */

  vector<int> prefixSum(n + 1);
  prefixSum[1] = offset[1];
  for (int i = 1; i <= n; i++) {
    prefixSum[i] = prefixSum[i - 1] + offset[i];
  }
  /*
  for (auto x : prefixSum)
    cout << x << " ";
  cout << endl;
  */

  while (q--) {
    int l, r;
    cin >> l >> r;
    int res = 0;
    if (r - l > 1) {
      res += prefixSum[r - 1] - prefixSum[l];
    }

    res += v[l] - 1;
    if (l != r) {
      res += max(v[l + 1] - v[l] - 1, 0);
    }
    res += k - v[r];
    if (l != r) {
      res += max(v[r] - v[r - 1] - 1, 0);
    }

    cout << res << '\n';
  }
}
