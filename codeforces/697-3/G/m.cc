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
    vector<long long> v(n);
    vector<long long> cnt(2e5 + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      cnt[v[i]]++;
    }

    sort(v.begin(), v.end());
    vector<long long> dp(2e5 + 1, 0); // max num <= x that is compatible with x
    long long best = 0;
    for (int i = 1; i < dp.size(); i++) {
      if (cnt[i] == 0)
        continue;

      dp[i] += cnt[i];
      // use "sieve" for significant speedup!
      for (int j = 2 * i; j < dp.size(); j += i) {
        dp[j] = max(dp[j], dp[i]);
      }
      best = max(best, dp[i]);
    }

    cout << n - best << '\n';
  }
}
