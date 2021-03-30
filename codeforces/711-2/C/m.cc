#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
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
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(2, 0)));

    for (int j = 1; j <= k; j++) {
      for (int d = 0; d < 2; d++) {
        if (d == 0) {  // left
          for (int i = 0; i < n; i++) {
            if (j == 1) {
              dp[i][j][d] = 1;
              continue;
            }
            dp[i][j][d] = 2;
            dp[i][j][d] += ((i - 1 >= 0 ? dp[i - 1][j][d] - 1 : 0) % P + (i + 1 < n ? dp[i + 1][j - 1][1 - d] - 1 : 0) % P) % P;
          }
        } else {  // right
          for (int i = n - 1; i >= 0; i--) {
            if (j == 1) {
              dp[i][j][d] = 1;
              continue;
            }
            dp[i][j][d] = 2;
            dp[i][j][d] += ((i + 1 < n ? dp[i + 1][j][d] - 1 : 0) % P + (i - 1 >= 0 ? dp[i - 1][j - 1][1 - d] - 1 : 0) % P) % P;
          }
        }
      }
    }

    cout << dp[0][k][1] << '\n';
  }
}
