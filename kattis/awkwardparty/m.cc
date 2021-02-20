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
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> m;  // last pos
  int res = n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (m.count(x) == 0) {
      m[x] = i;
      continue;
    }
    int tmp = i - m[x];
    res = min(res, tmp);
    m[x] = i;
  }
  cout << res << '\n';
}
