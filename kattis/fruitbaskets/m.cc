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
  int n;
  cin >> n;
  vector<int> v(n);
  int tolSum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    tolSum += v[i];
  }
  vector<vector<long long>> dp(n, vector<long long>(tolSum + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= tolSum; j++) {
      if (j == 0) {
        dp[i][j] = 1;
      } else if (i == 0) {
        dp[i][j] = v[i] == j;
      } else {
        dp[i][j] = dp[i - 1][j] + (j - v[i] >= 0 ? dp[i - 1][j - v[i]] : 0);
      }
    }
  }
  long long res = 0;
  for (long long i = 200; i <= tolSum; i++) {
    if (dp[n - 1][i]) {
      res += dp[n - 1][i] * i;
    }
  }
  cout << res << '\n';
}
