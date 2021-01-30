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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  double semip = (a + b + c + d) / 2.0;
  double k2 = (semip - a) * (semip - b) * (semip - c) * (semip - d);
  cout << fixed << setprecision(6) << sqrt(k2) << '\n';
}
