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

long long sumDigit(long long x) {
  // cout << "x: " << x;
  long long res = 0;
  while (x != 0) {
    res += x % 10;
    x /= 10;
  }
  // cout << " res: " << res << '\n';
  return res;
}

long long gcdSum(long long x) {
  return gcd(x, sumDigit(x));
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
    long long n;
    cin >> n;
    while (gcdSum(n) == 1) n++;
    cout << n << '\n';
  }
}
