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
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, f, s, t;
  cin >> n >> m >> f >> s >> t;
  vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());  // (label, cost)
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adjList[a].push_back({b, c});
    adjList[b].push_back({a, c});
  }

  vector<long long> sourceD(n, 1e11);
  sourceD[s] = 0;
  set<pair<long long, int>> pq;
  for (int i = 0; i < n; i++) {
    pq.insert({sourceD[i], i});
  }
  while (pq.size() > 0) {
    auto [d, nd] = *pq.begin();
    pq.erase(pq.begin());

    if (d != sourceD[nd]) continue;

    for (auto [nei, cos] : adjList[nd]) {
      if (d + cos < sourceD[nei]) {
        sourceD[nei] = d + cos;
        pq.insert({sourceD[nei], nei});
      }
    }
  }

  vector<long long> destD(n, 1e11);
  destD[t] = 0;
  for (int i = 0; i < n; i++) {
    pq.insert({destD[i], i});
  }
  while (pq.size() > 0) {
    auto [d, nd] = *pq.begin();
    pq.erase(pq.begin());

    if (d != destD[nd]) continue;

    for (auto [nei, cos] : adjList[nd]) {
      if (d + cos < destD[nei]) {
        destD[nei] = d + cos;
        pq.insert({destD[nei], nei});
      }
    }
  }

  long long ans = sourceD[t];

  for (int i = 0; i < f; i++) {
    int u, v;
    cin >> u >> v;

    if (sourceD[u] + destD[v] < ans) {
      ans = sourceD[u] + destD[v];
    }
  }
  cout << ans << '\n';
}
