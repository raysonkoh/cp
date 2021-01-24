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
  int n;
  cin >> n;
  vector<double> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    double d;
    cin >> s >> d;
    v[i] = d;
  }
  sort(v.rbegin(), v.rend());
  double res = 0;
  for (int i = 1; i <= n; i++) {
    res += i * v[i - 1];
  }
  cout << fixed << setprecision(4) << res << '\n';
}
