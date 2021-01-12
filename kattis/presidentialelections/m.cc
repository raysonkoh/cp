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

  int s;
  cin >> s;
  vector<int> d(s);
  vector<int> c(s);
  vector<int> f(s);
  vector<int> u(s);
  vector<int> expectVoters(s); // expected num of voters to get majority
  int tolDel = 0;

  for (int i = 0; i < s; i++) {
    cin >> d[i] >> c[i] >> f[i] >> u[i];
    tolDel += d[i];
    expectVoters[i] = (c[i] + f[i] + u[i]) / 2 + 1;
  }

  int expectDel = (tolDel / 2) + 1;
  int maxDel = 2017;
  // int maxDel = 128;

  vector<vector<int>> dp(s, vector<int>(maxDel, -1));
  for (int i = s - 1; i >= 0; i--) {
    for (int j = 0; j < maxDel; j++) {
      if (j >= expectDel) {
        dp[i][j] = 0;
      } else if (i == s - 1) {
        int tolSupport = j;
        int cost = 0;
        if (c[i] >= expectVoters[i]) {
          tolSupport += d[i];
        } else if (c[i] + u[i] >= expectVoters[i]) {
          tolSupport += d[i];
          cost += expectVoters[i] - c[i];
        }
        dp[i][j] = (tolSupport >= expectDel ? cost : -1);
      } else {
        if (c[i] >= expectVoters[i]) {
          if (j + d[i] < maxDel)
            dp[i][j] = dp[i + 1][j + d[i]];
          else
            dp[i][j] = 0;
        } else if (c[i] + u[i] >= expectVoters[i]) {
          int flip = (j + d[i] < maxDel ? dp[i + 1][j + d[i]] : 0);
          int noFlip = dp[i + 1][j];
          if (flip == -1 && noFlip == -1) {
            dp[i][j] = -1;
          } else if (flip == -1) {
            dp[i][j] = noFlip;
          } else if (noFlip == -1) {
            dp[i][j] = flip + expectVoters[i] - c[i];
          } else {
            // cout << "flip: " << flip << " noFlip: " << noFlip << endl;
            dp[i][j] = min(flip + expectVoters[i] - c[i], noFlip);
          }
        } else {
          dp[i][j] = dp[i + 1][j];
        }
      }

      // cout << "i: " << i << " j: " << j << " val: " << dp[i][j] << endl;
    }
  }

  if (dp[0][0] == -1)
    cout << "impossible\n";
  else
    cout << dp[0][0] << '\n';
}