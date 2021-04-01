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
    double x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    bool can = false;
    for (int i = 0; i < n; i++) {
      double xx, yy;
      cin >> xx >> yy;
      if (abs(x - xx) * abs(x - xx) + abs(y - yy) * abs(y - yy) <= 8 * 8) {
        can = true;
      }
    }
    cout << (can ? "light a candle" : "curse the darkness") << '\n';
  }
}
