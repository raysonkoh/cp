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

int sumDigits(int x) {
  int res = 0;
  while (x) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  map<int, vector<int>> m;

  for (int i = 0; i <= 100000; i++) {
    int d = sumDigits(i);
    if (m.count(d) == 0)
      m[d] = vector<int>();
    m[d].push_back(i);
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int d = sumDigits(n);
    vector<int> v = m[d - 1];
    auto ptr = prev(lower_bound(v.begin(), v.end(), n));
    cout << *ptr << '\n';
  }
}
