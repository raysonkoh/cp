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

  priority_queue<tuple<long long, int, bool, bool>, vector<tuple<long long, int, bool, bool>>, greater<tuple<long long, int, bool, bool>>> pq;
  vector<vector<long long>> dist(n, vector<long long>(4, 1e18));
  dist[0][0] = 0;
  pq.push({dist[0][0], 0, false, false});

  while (pq.size() > 0) {
    auto [d, node, hasMinus, hasAdd] = pq.top();
    // cout << "d: " << d << " node: " << node << " hasMinus: " << hasMinus << " hasAdd: " << hasAdd << endl;
    pq.pop();
    if (!hasMinus && !hasAdd) {
      if (dist[node][0] < d) {
        continue;
      }
    } else if (!hasMinus && hasAdd) {
      if (dist[node][1] < d) {
        continue;
      }
    } else if (hasMinus && !hasAdd) {
      if (dist[node][2] < d) {
        continue;
      }
    } else {
      if (dist[node][3] < d) {
        continue;
      }
    }

    for (auto [wt, nei] : adjList[node]) {
      if (!hasMinus && !hasAdd) {
        if (d + wt < dist[nei][0]) {
          dist[nei][0] = d + wt;
          pq.push({dist[nei][0], nei, hasMinus, hasAdd});
        }

        if (d + wt + wt < dist[nei][1]) {
          dist[nei][1] = d + wt + wt;
          pq.push({dist[nei][1], nei, hasMinus, !hasAdd});
        }

        if (d < dist[nei][2]) {
          dist[nei][2] = d;
          pq.push({dist[nei][2], nei, !hasMinus, hasAdd});
        }

        if (d + wt < dist[nei][3]) {
          dist[nei][3] = d + wt;
          pq.push({dist[nei][3], nei, !hasMinus, !hasAdd});
        }
      } else if (!hasMinus && hasAdd) {
        if (d + wt < dist[nei][1]) {
          dist[nei][1] = d + wt;
          pq.push({dist[nei][1], nei, hasMinus, hasAdd});
        }

        if (d < dist[nei][3]) {
          dist[nei][3] = d;
          pq.push({dist[nei][3], nei, !hasMinus, hasAdd});
        }
      } else if (hasMinus && !hasAdd) {
        if (d + wt < dist[nei][2]) {
          dist[nei][2] = d + wt;
          pq.push({dist[nei][2], nei, hasMinus, hasAdd});
        }
        if (d + wt + wt < dist[nei][3]) {
          dist[nei][3] = d + wt + wt;
          pq.push({dist[nei][3], nei, hasMinus, !hasAdd});
        }
      } else {
        if (d + wt < dist[nei][3]) {
          dist[nei][3] = d + wt;
          pq.push({dist[nei][3], nei, hasMinus, hasAdd});
        }
      }
    }
  }

  for (int i = 1; i < n; i++) {
    cout << dist[i][3] << ' ';
  }
  cout << '\n';
}
