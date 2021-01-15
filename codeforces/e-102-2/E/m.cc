#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<long long, int>>> adjList(n, vector<pair<long long, int>>()); // (wt, nei)
  for (int i = 0; i < m; i++) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    u--;
    v--;
    adjList[u].push_back({w, v});
    adjList[v].push_back({w, u});
  }

  long long INF = 1e18;
  vector<long long> maxEdgeWt(n);
  vector<long long> minEdgeWt(n);
  vector<long long> dist(n, INF);
  vector<int> pathLength(n);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

  maxEdgeWt[0] = 0;
  minEdgeWt[0] = 0;
  dist[0] = 0;
  pathLength[0] = 0;
  pq.push({pathLength[0], 0});

  while (pq.size() > 0) {
    auto [d, nd] = pq.top();
    pq.pop();
    for (auto [wt, nei] : adjList[nd]) {
      long long tmpMax, tmpMin;
      if (pathLength[nd] == 0) {
        tmpMax = wt;
        tmpMin = wt;
      } else {
        tmpMax = max(wt, maxEdgeWt[nd]);
        tmpMin = min(wt, minEdgeWt[nd]);
      }

      // long long newDist = dist[nd] + maxEdgeWt[nd] - minEdgeWt[nd] + wt - tmpMax + tmpMin;
      long long newDist = d + wt;
      // cout << "from: " << nd << " to " << nei << " dist: " << d << " newDist: " << newDist << endl;
      if (newDist < dist[nei]) {
        maxEdgeWt[nei] = tmpMax;
        minEdgeWt[nei] = tmpMin;
        dist[nei] = newDist;
        pathLength[nei] = pathLength[nd] + 1;
        pq.push({dist[nei], nei});
      }
    }
  }

  /*
  for (auto x : maxEdgeWt) {
    cout << x << " ";
  }
  cout << endl;

  for (auto x : minEdgeWt) {
    cout << x << " ";
  }
  cout << endl;

  for (auto x : pathLength) {
    cout << x << " ";
  }
  cout << endl;
  */

  for (int i = 1; i < n; i++) {
    if (i == n - 1) {
      cout << dist[i] - maxEdgeWt[i] + minEdgeWt[i];
    } else {
      cout << dist[i] - maxEdgeWt[i] + minEdgeWt[i] << " ";
    }
  }
  cout << '\n';
}
