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
  int s, n;
  cin >> s >> n;
  /*
    1 - folded
    2 - fist open
    3 - palm down
  */
  vector<pair<int, int>> v(n); // (state, label)
  for (int i = 0; i < n; i++) {
    v[i] = {1, i};
  }
  int curr = 0;
  int sz = n;
  while (sz > 1) {
    int i = curr;
    int ct = 1;
    while (ct < s) {
      ct++;
      i++;
      i %= sz;
    }
    auto [state, last] = v[i];
    // cout << "state: " << state << " last: " << last + 1 << '\n';
    if (state == 1) {
      v[i].first = 2;
      v.insert(v.begin() + i, {2, last});
      curr = i;
      sz++;
    } else if (state == 2) {
      v[i].first = 3;
      curr = (i + 1) % sz;
    } else if (state == 3) {
      v.erase(v.begin() + i);
      sz--;
      curr = i % sz;
    }
  }

  cout << v[0].second + 1 << '\n';
}
