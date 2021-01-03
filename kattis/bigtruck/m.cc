#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> items(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> items[i];
  }
  int m;
  cin >> m;
  vector<vector<pair<int, int>>> adjList(n + 1, vector<pair<int, int>>()); // (wt, label)
  for (int i = 0; i < m; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    adjList[a].push_back(make_pair(d, b));
    adjList[b].push_back(make_pair(d, a));
  }
  vector<int> dist(n + 1, INF);
  vector<int> numItems(n + 1, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[1] = 0;
  numItems[1] = items[1];
  pq.push(make_pair(dist[1], 1));
  while (pq.size() > 0) {
    auto [d, node] = pq.top();
    pq.pop();
    for (auto [wt, nei] : adjList[node]) {
      if (d + wt < dist[nei]) {
        dist[nei] = d + wt;
        numItems[nei] = numItems[node] + items[nei];
        pq.push(make_pair(dist[nei], nei));
      } else if (d + wt == dist[nei]) {
        numItems[nei] = max(numItems[nei], numItems[node] + items[nei]);
      }
    }
  }
  if (dist[n] == INF) {
    cout << "impossible\n";
  } else {
    cout << dist[n] << " " << numItems[n] << "\n";
  }
}
