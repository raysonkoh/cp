#include <algorithm>
#include <cassert>
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

/*
  YOU CAN DO THIS!! ;)
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
    double s = x + y;
    double p = x * y;
    double h1 = (4 * s + sqrt(16 * s * s - 4 * 12 * p)) / 24;
    double h2 = (4 * s - sqrt(16 * s * s - 4 * 12 * p)) / 24;
    double res = max((x - 2 * h1) * (y - 2 * h1) * h1, (x - 2 * h2) * (y - 2 * h2) * h2);
    cout << fixed << setprecision(6) << res << '\n';
  }
}
