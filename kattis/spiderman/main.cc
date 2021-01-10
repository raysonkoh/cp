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
  while (n--) {
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
      cin >> v[i];

    int maxSz = 1001;
    vector<vector<int>> dp(m, vector<int>(maxSz, maxSz + 1)); // -1 indicates IMPOSSIBLE
    vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(maxSz));

    for (int i = m - 1; i >= 0; i--) {
      for (int j = 0; j < maxSz; j++) {
        if (i == m - 1) {
          if (v[i] == j) {
            dp[i][j] = j;
          } else {
            dp[i][j] = maxSz + 1;
          }
          parent[i][j] = {-1, -1};
        } else {
          if (j + v[i] < maxSz && dp[i + 1][j + v[i]] != maxSz + 1) {
            if (dp[i + 1][j + v[i]] < dp[i][j]) {
              dp[i][j] = dp[i + 1][j + v[i]];
              parent[i][j] = {i + 1, j + v[i]};
            }
          }

          if (j - v[i] >= 0 && dp[i + 1][j - v[i]] != maxSz + 1) {
            if (dp[i + 1][j - v[i]] < dp[i][j]) {
              dp[i][j] = dp[i + 1][j - v[i]];
              parent[i][j] = {i + 1, j - v[i]};
            }
          }

          if (dp[i][j] != maxSz + 1)
            dp[i][j] = max(dp[i][j], j);
        }
        // cout << "(" << i << ", " << j << "): " << dp[i][j] << endl;
      }
    }

    if (dp[0][0] == maxSz + 1)
      cout << "IMPOSSIBLE\n";
    else {
      pair<int, int> currP = {0, 0};
      pair<int, int> par = parent[currP.first][currP.second];
      vector<char> res;
      while (par.first != -1 && par.second != -1) {
        if (par.second > currP.second) {
          // U
          res.push_back('U');
        } else {
          // D
          res.push_back('D');
        }
        currP = par;
        par = parent[currP.first][currP.second];
      }

      res.push_back('D'); // last move confirm is D

      for (auto ch : res) {
        cout << ch;
      }
      cout << '\n';

      // cout << dp[0][0] << '\n';
    }
  }
}