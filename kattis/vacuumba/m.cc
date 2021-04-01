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
    int m;
    cin >> m;
    double x = 0;
    double y = 0;
    double ang = 0;
    while (m--) {
      double a, d;
      cin >> a >> d;
      ang += (M_PI / 180.0) * a;
      y += d * cos(ang);
      x -= d * sin(ang);
      // cout << "ang: " << ang << " d: " << d << " x: " << x << " y: " << y << endl;
    }
    cout << fixed << setprecision(8) << x << " " << y << '\n';
  }
}
