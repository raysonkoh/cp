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
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<set<int>> charPos(26);
  char c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    charPos[c - 'a'].insert(i);
  }
  int prv = -1;
  int res = 0;
  vector<pair<int, char>> perm(m);
  for (int i = 0; i < m; i++) {
    cin >> c;
    int pos = c - 'a';
    if (i == 0) {
      prv = *charPos[pos].begin();
      charPos[pos].erase(charPos[pos].begin());
    } else {
      auto it = charPos[pos].lower_bound(prv);
      res = max(res, *it - prv);
      prv = *it;
      charPos[pos].erase(it);
    }
    perm[i] = {prv, c};
  }
  // cout << "res: " << res << endl;
  for (int i = m - 1; i >= 1; i--) {
    auto [a, b] = perm[i];
    int pos = b - 'a';
    if (charPos[pos].size() > 0) {
      prv = (i == m - 1) ? n + 1 : perm[i + 1].first;
      // cout << "prv: " << prv << endl;
      auto it = charPos[pos].lower_bound(prv);
      if (it == charPos[pos].begin()) {
        // cout << "HERE" << endl;
        continue;
      }
      int rightmost = *prev(it);
      if (rightmost > a) {
        charPos[pos].insert(a);
        charPos[pos].erase(rightmost);
        // cout << "changing pos of " << b << " from " << a << " to " << rightmost << endl;
        res = max(res, rightmost - perm[i - 1].first);
        perm[i].first = rightmost;
      }
    }
  }

  cout << res << '\n';
}
