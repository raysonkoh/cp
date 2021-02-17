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
  vector<int> ns(4);
  for (int i = 0; i < 4; i++)
    cin >> ns[i];

  vector<vector<int>> cost(4);
  for (int i = 0; i < 4; i++) {
    cost[i].resize(ns[i]);
    for (int j = 0; j < ns[i]; j++) {
      cin >> cost[i][j];
    }
  }

  vector<vector<vector<int>>> bad(3);
  for (int i = 0; i < 3; i++) {
    int m;
    cin >> m;
    bad[i].resize(ns[i]);
    for (int j = 0; j < m; j++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      bad[i][x].push_back(y);
    }
  }

  // compare (i) with (i + 1)
  for (int i = 2; i >= 0; i--) {
    multiset<int> ms;
    for (auto x : cost[i + 1]) {
      ms.insert(x);
    }

    for (int j = 0; j < ns[i]; j++) {
      for (auto b : bad[i][j]) {
        ms.erase(ms.find(cost[i + 1][b]));
      }

      if (ms.size() > 0)
        cost[i][j] += *ms.begin();
      else
        cost[i][j] += 1e9;

      for (auto b : bad[i][j]) {
        ms.insert(cost[i + 1][b]);
      }
    }
  }

  int res = *min_element(cost[0].begin(), cost[0].end());
  cout << (res >= 1e9 ? -1 : res) << '\n';
}
