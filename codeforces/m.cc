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

int ct = 0;

void dfs(int curr, vector<vector<pair<int, int>>> &adjList, set<int> &seen, vector<int> &res) {
  seen.insert(curr);
  bool hasRecursed = false;

  for (auto [t, nei] : adjList[curr]) {
    if (seen.count(nei) > 0)
      continue;
    if (t == 2)
      ct++;
    dfs(nei, adjList, seen, res);
    hasRecursed = true;
  }
  if (!hasRecursed) {
    // leaf
    if (ct > 0) {
      res.push_back(curr);
      ct = 0;
    }
    return;
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> adjList(n + 1, vector<pair<int, int>>()); // (type, label)
  for (int i = 0; i < n - 1; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    adjList[x].push_back({t, y});
    adjList[y].push_back({t, x});
  }
  for (int i = 1; i <= n; i++) {
    sort(adjList[i].rbegin(), adjList[i].rend());
  }
  vector<int> res;
  set<int> seen;
  dfs(1, adjList, seen, res);
  //assert(ct == 0);
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
