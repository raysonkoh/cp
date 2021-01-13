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
  int t;
  cin >> t;
  while (t--) {
    int pr;
    cin >> pr;
    int n;
    cin >> n;
    vector<int> v(n);
    int maxSize = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      maxSize += v[i];
    }

    vector<vector<int>> dp(n, vector<int>(maxSize + 1, n + 1)); // min num of coins to change to j

    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < maxSize + 1; j++) {
        if (j == 0) {
          dp[i][j] = 0;
        } else if (i == n - 1) {
          dp[i][j] = (v[i] == j ? 1 : n + 1);
        } else {
          int a = dp[i + 1][j];
          int b = (j - v[i] >= 0) ? dp[i + 1][j - v[i]] : n + 1;
          if (a == n + 1 && b == n + 1) {
            dp[i][j] = n + 1;
          } else if (a == n + 1) {
            dp[i][j] = b + 1;
          } else if (b == n + 1) {
            dp[i][j] = a;
          } else {
            dp[i][j] = min(a, b + 1);
          }
        }
      }
    }

    for (int i = 0; i < maxSize + 1; i++) {
      if (dp[0][i] != n + 1 && i >= pr) {
        cout << i << " " << dp[0][i] << '\n';
        break;
      }
    }
  }
}