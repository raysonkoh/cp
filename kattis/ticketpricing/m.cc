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
  int n, w;
  cin >> n >> w;
  vector<vector<int>> p(w + 1);
  vector<vector<int>> quant(w + 1);
  for (int i = w; i >= 0; i--) {
    int k;
    cin >> k;
    vector<int> tmp(k);
    for (int j = 0; j < k; j++)
      cin >> tmp[j];
    p[i] = tmp;
    vector<int> tmp2(k);
    for (int j = 0; j < k; j++)
      cin >> tmp2[j];
    quant[i] = tmp2;
  }

  vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0)); // max revenue

  for (int j = 0; j < w + 1; j++) {
    for (int i = 0; i < n + 1; i++) {
      for (int t = 0; t < p[j].size(); t++) {
        int pr = p[j][t];
        int quan = quant[j][t];
        int sellQuan = min(i, quan);
        if (j == 0) {
          dp[i][j] = max(dp[i][j], sellQuan * pr);
        } else {
          dp[i][j] = max(dp[i][j], sellQuan * pr + dp[i - sellQuan][j - 1]);
        }
      }
    }
  }

  int best = 0;

  for (int i = 0; i < p[w].size(); i++) {
    int pr = p[w][i];
    int quan = quant[w][i];
    int sellQuan = min(n, quan);
    if (sellQuan * pr + dp[n - sellQuan][w - 1] == dp[n][w]) {
      if (best == 0) {
        best = pr;
      } else if (pr < best) {
        best = pr;
      }
    }
  }

  cout << dp[n][w] << '\n';
  cout << best << '\n';
}
