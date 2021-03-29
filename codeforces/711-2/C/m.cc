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

void printVect(vector<long long> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

long long get(int i, int k, int d, vector<vector<vector<long long>>> &dp) {
  if (k == 1) {
    dp[i][k][d] = 1;
    return 1;
  }

  if (dp[i][k][d] != -1) return dp[i][k][d];
  long long res = 2;
  if (d == 1) {  // right
    if (i + 1 < dp.size()) res += get(i + 1, k, d, dp) - 1;
    res %= P;
    if (i - 1 >= 0) res += get(i - 1, k - 1, 1 - d, dp) - 1;
    res %= P;
  } else {  // left
    if (i - 1 >= 0) res += get(i - 1, k, d, dp) - 1;
    res %= P;
    if (i + 1 < dp.size()) res += get(i + 1, k - 1, 1 - d, dp) - 1;
    res %= P;
  }
  dp[i][k][d] = res;
  return res;
}

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
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(2, -1)));

    long long x = get(0, k, 1, dp);

    cout << x << '\n';
  }
}
