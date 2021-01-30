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
  int n;
  cin >> n;
  vector<bool> isfilled(n + 1, false);
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.rbegin(), v.rend());
  double num = n;
  bool can = true;
  double minFrac = 1.0;
  for (int i = 0; i < v.size(); i++, num--) {
    if (num < v[i]) {
      can = false;
      break;
    } else {
      minFrac = min(minFrac, v[i] / num);
    }
  }
  if (!can)
    cout << "impossible\n";
  else
    cout << fixed << setprecision(6) << minFrac << '\n';
}
