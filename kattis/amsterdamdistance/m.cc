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
  double m, n, r;
  cin >> m >> n >> r;
  int ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  double yincr = r / n;
  vector<double> xincr(n + 1);
  xincr[0] = 0;
  double curr = yincr;
  for (int i = 1; i <= n; i++) {
    xincr[i] = (M_PI * curr) / m;
    curr += yincr;
  }

  double res = ay * yincr + by * yincr;
  for (int ypos = 1; ypos <= n; ypos++) {
    res = min(res, abs(ay - ypos) * yincr + abs(ax - bx) * xincr[ypos] + abs(ypos - by) * yincr);
  }

  cout << fixed << setprecision(8) << res << '\n';
}
