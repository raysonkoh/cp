#include <iostream>
#include <vector>

using namespace std;

int IMPOSSIBLE = -1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1];
  }
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(3)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k + 1; j++) {
      for (int s = 0; s < 3; s++) {

        if (i == 0) {
          if (j == 0) {
            if (s == 0) {
              dp[i][j][s] = IMPOSSIBLE;
            } else if (s == 1) {
              dp[i][j][s] = IMPOSSIBLE;
            } else {
              dp[i][j][s] = v[i][0] + v[i][1];
            }
          } else if (j > 1) {
            dp[i][j][s] = IMPOSSIBLE;
          } else if (s == 0) {
            dp[i][j][s] = v[i][1];
          } else if (s == 1) {
            dp[i][j][s] = v[i][0];
          } else {
            dp[i][j][s] = IMPOSSIBLE;
          }
        } else if (j == 0) {
          // no need to block
          if (s == 0) {
            dp[i][j][s] = IMPOSSIBLE;
          } else if (s == 1) {
            dp[i][j][s] = IMPOSSIBLE;
          } else {
            dp[i][j][s] = dp[i - 1][j][s] + v[i][0] + v[i][1];
          }
        } else if (s == 0) {
          // block left
          int a = dp[i - 1][j - 1][s];
          int b = dp[i - 1][j - 1][2];

          int allMax = max(a, b);
          int add = v[i][1];

          if (allMax == IMPOSSIBLE) {
            dp[i][j][s] = IMPOSSIBLE;
          } else {
            dp[i][j][s] = allMax + add;
          }
        } else if (s == 1) {
          // block right
          int a = dp[i - 1][j - 1][s];
          int b = dp[i - 1][j - 1][2];

          int allMax = max(a, b);
          int add = v[i][0];

          if (allMax == IMPOSSIBLE) {
            dp[i][j][s] = IMPOSSIBLE;
          } else {
            dp[i][j][s] = allMax + add;
          }
        } else {
          // block none
          int a = dp[i - 1][j][0];
          int b = dp[i - 1][j][1];
          int c = dp[i - 1][j][2];

          int allMax = max(a, max(b, c));
          int add = v[i][0] + v[i][1];

          if (allMax == IMPOSSIBLE) {
            dp[i][j][s] = IMPOSSIBLE;
          } else {
            dp[i][j][s] = allMax + add;
          }
        }
        // cout << "(" << i << "," << j << "," << s << ") : " << dp[i][j][s]
        //     << endl;
      }
    }
  }

  cout << max(dp[n - 1][k][0], max(dp[n - 1][k][1], dp[n - 1][k][2])) << endl;
}