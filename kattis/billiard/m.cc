#include <algorithm>
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

double r2dp(double x) {
  int tmp = x * 100.0;
  double tmp2 = ((double)tmp) / 100.0;
  if (x - tmp2 >= 0.005) {
    tmp2 += 0.01;
  }
  return tmp2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double a, b, s, m, n;
  while (cin >> a >> b >> s >> m >> n) {
    if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0)
      break;
    double first = a * m / s;
    double second = b * n / s;
    double angle = atan(second / first) * 180.0 / M_PI;
    double vel = sqrt(first * first + second * second);
    cout << fixed << setprecision(2) << angle << ' ' << vel << '\n';
  }
}
