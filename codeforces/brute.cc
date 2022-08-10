#include <algorithm>
#include <bitset>
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

//#define GOOGLE

void solve() {
}

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
  4. Can't prove a pattern (Esp Game Theory)? Brute force for small numbers and observe!
  5. For Binary-search problems: Determine F[x] is monotonically incr or decr, then use the templates accordingly
  6. For nCk, use table form / mod inverse rather than just calculating it directly for precision reasons
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // cin >> t;
#ifdef GOOGLE
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
#else
  while (t--) {
    solve();
  }
#endif
}
