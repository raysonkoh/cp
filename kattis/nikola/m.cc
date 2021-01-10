#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<vector<int>> dp(n, vector<int>(n, 1e9));
  for (int j = n - 1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        dp[i][j] = v[i];
      } else {
        if (i - j >= 0 && dp[i - j][j] != 1e9)
          dp[i][j] = min(dp[i][j], dp[i - j][j]);

        if (i + j + 1 < n && j + 1 < n && dp[i + j + 1][j + 1] != 1e9)
          dp[i][j] = min(dp[i][j], dp[i + j + 1][j + 1]);

        if (dp[i][j] != 1e9)
          dp[i][j] += v[i];
      }

      // cout << "(" << i << ", " << j << "): " << dp[i][j] << endl;
    }
  }

  cout << dp[0][0] - v[0] << '\n';
}
