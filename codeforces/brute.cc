#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

const long long P = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

int dfs(int curr, vector<vector<pair<int, int>>> &adjList, set<int> &seen, vector<int> &ct, vector<bool> &isWhite) {
  seen.insert(curr);
  int res = isWhite[curr];

  for (auto [t, nei] : adjList[curr]) {
    if (seen.count(nei) > 0)
      continue;
    res += dfs(nei, adjList, seen, ct, isWhite);
  }
  ct[curr] = res;
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> adjList(n + 1, vector<pair<int, int>>()); // (type, label)
  vector<bool> isWhite(n + 1, false);
  for (int i = 0; i < n - 1; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    adjList[x].push_back({t, y});
    adjList[y].push_back({t, x});
    if (t == 2) {
      isWhite[x] = true;
      isWhite[y] = true;
    }
  }
  vector<int> ct(n + 1, 0);
  set<int> seen;
  dfs(1, adjList, seen, ct, isWhite);
  //assert(ct == 0);
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (ct[i] == 1 && isWhite[i])
      res.push_back(i);
  }
  cout << res.size() << '\n';
  if (res.size() > 0) {
    for (auto x : res)
      cout << x << " ";
    cout << '\n';
  }
}

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // int t;
  // cin >> t;
  while (t--) {
    solve();
  }
}