#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int c, n;
  while (cin >> c >> n) {
    vector<int> w(n, 0);
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
      int pr, wt;
      cin >> pr >> wt;
      w[i] = wt;
      p[i] = pr;
    }

    vector<vector<int>> dp(n, vector<int>(c));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < c; j++) {
        if (i == 0) {
          if (w[i] <= j) {
            dp[i][j] = p[i];
          }
        } else {
          if (j - w[i] >= 0) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + p[i]);
          } else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }
    cout << dp[n - 1][c - 1] << endl;
  }
}