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
    int n;
    cin >> n;
    vector<long long> xV;
    vector<long long> yV;
    for (int i = 0; i < 2 * n; i++) {
      long long x, y;
      cin >> x >> y;
      if (x == 0) {
        yV.push_back(abs(y));
      } else {
        xV.push_back(abs(x));
      }
    }
    sort(xV.begin(), xV.end());
    sort(yV.begin(), yV.end());

    assert(xV.size() == n);
    assert(yV.size() == n);

    double res = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
      // cout << xV[i] << " " << yV[j] << endl;
      res += sqrt((xV[i] * xV[i]) + (yV[i] * yV[i]));
    }

    cout << fixed << setprecision(9) << res << '\n';
  }
}
