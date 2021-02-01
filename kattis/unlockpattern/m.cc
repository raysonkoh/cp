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
  vector<pair<int, int>> v(9);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int x;
      cin >> x;
      x--;
      v[x] = {i, j};
    }
  }
  double res = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    auto [cx, cy] = v[i];
    auto [nx, ny] = v[i + 1];
    double a = abs(cx - nx);
    double b = abs(cy - ny);
    double d = sqrt(a * a + b * b);
    res += d;
  }
  cout << fixed << setprecision(6) << res << '\n';
}
