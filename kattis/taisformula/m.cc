#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  vector<double> t(n);
  vector<double> v(n);

  for (int i = 0; i < n; i++) {
    cin >> t[i] >> v[i];
  }
  double res = 0;
  for (int i = 0; i < n - 1; i++) {
    double xoffset = v[i] + v[i + 1];
    long long toffset = t[i + 1] - t[i];

    res += (xoffset / 2.0) * toffset;
  }

  cout << fixed << setprecision(8) << res / 1000.0 << '\n';
}