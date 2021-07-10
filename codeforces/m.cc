#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

const long long P = 1e9 + 7;

//#define RAY_DP

#ifdef RAY_DP
const int N = 1005;
long long dp[N];

void reset() {
  for (int i = 0; i < N; i++)
    dp[i] = 0;
}
#endif

void solve() {
}

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
  4. Can't prove a pattern (Esp Game Theory)? Brute force for small numbers and observe!
  5. For Binary-search problems: Determine F[x] is monotonically incr or decr, then use the templates accordingly
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
#ifdef RAY_DP
    reset();
#endif
    solve();
  }
}
