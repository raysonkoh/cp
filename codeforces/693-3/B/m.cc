#include <iostream>
#include <vector>

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
    vector<int> v(n);
    int tolSum = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      tolSum += v[i];
    }

    if (tolSum % 2 == 1) {
      cout << "NO\n";
      continue;
    }

    vector<vector<bool>> dp(n, vector<bool>(tolSum + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < tolSum + 1; j++) {
        if (i == 0) {
          dp[i][j] = (v[i] == j);
        } else {
          if (j - v[i] < 0) {
            dp[i][j] = dp[i - 1][j];
          } else {
            dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - v[i]]);
          }
        }
      }
    }

    cout << (dp[n - 1][tolSum / 2] ? "YES" : "NO") << "\n";
  }
}
