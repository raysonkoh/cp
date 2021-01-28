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
  vector<vector<bool>> dp(10, vector<bool>(100, false));
  for (int i = 1; i < dp.size(); i++) {
    for (int j = 0; j < dp[i].size(); j++) {
      if (j == 0) {
        dp[i][j] = true;
      } else {
        for (int k = j - 1; k >= 0; k--) {
          string s = to_string(j - k);
          if (dp[i][k] && s.find(to_string(i)) != s.npos) {
            dp[i][j] = true;
            break;
          }
        }
      }
    }
  }

  while (t--) {
    int q, d;
    cin >> q >> d;
    for (int i = 0; i < q; i++) {
      int x;
      cin >> x;
      if (x > d * 10 + d) {
        cout << "YES\n";
      } else {
        cout << (dp[d][x] ? "YES\n" : "NO\n");
      }
    }
  }
}
