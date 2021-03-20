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
  int caseNum = 1;
  while (t--) {
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<long long>> prefixMatrix(n, vector<long long>(k));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        int x;
        cin >> x;
        if (j == 0) {
          prefixMatrix[i][j] = x;
        } else {
          prefixMatrix[i][j] = x + prefixMatrix[i][j - 1];
        }
      }
    }

    // dp[i][j]: max val for first i rows choosing j plates
    // dp[i + 1][j'] = max_j(prefix(v[i][j]) + dp[i][j' - j])

    vector<vector<long long>> dp(n, vector<long long>(p + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= p; j++) {
        if (i > 0)
          dp[i][j] = dp[i - 1][j];
        for (int indx = 0; indx < min(j, k); indx++) {
          // cout << "i: " << i << " j: " << j << " indx: " << indx << endl;
          if (i == 0) {
            dp[i][j] = max(dp[i][j], prefixMatrix[i][indx]);
          } else {
            dp[i][j] = max(dp[i][j], prefixMatrix[i][indx] + dp[i - 1][j - (indx + 1)]);
          }
        }
      }
    }

    cout << "Case #" << caseNum << ": " << dp[n - 1][p] << '\n';
    caseNum++;
  }
}
