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
  int n, q;
  cin >> n >> q;
  vector<long long> v(n);
  long long g = 1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    g = gcd(g, v[i]);
  }
  while (q--) {
    int i, x;
    cin >> i >> x;
    v[i - 1] = v[i - 1] * x;
    g = gcd(g, v[i - 1]);
    cout << g << '\n';
  }
}
