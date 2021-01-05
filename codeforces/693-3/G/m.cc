#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void dfs(int i, vector<vector<int>> &adjList, vector<int> &dist, set<int> &seen, vector<int> &memo) {
  seen.insert(i);
  int res = dist[i];
  for (int nei : adjList[i]) {
    if (seen.count(nei) == 0 && dist[i] < dist[nei])
      dfs(nei, adjList, dist, seen, memo);

    if (dist[i] < dist[nei])
      res = min(res, memo[nei]);
    else
      res = min(res, dist[nei]);
  }
  memo[i] = res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n, vector<int>());
    while (m--) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adjList[u].push_back(v);
    }

    vector<int> dist(n);
    queue<pair<int, int>> q; // (d, label)
    set<int> seen;

    dist[0] = 0;
    seen.insert(0);
    q.push({dist[0], 0});
    while (q.size() > 0) {
      auto [d, nd] = q.front();
      q.pop();
      for (int nei : adjList[nd]) {
        if (seen.count(nei) == 0) {
          seen.insert(nei);
          dist[nei] = d + 1;
          q.push({dist[nei], nei});
        }
      }
    }

    seen.clear();
    vector<int> memo(n, -1);
    dfs(0, adjList, dist, seen, memo);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << memo[i];
    }
    cout << "\n";
  }
}
