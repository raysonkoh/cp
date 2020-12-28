#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, q, s;
  bool isFirst = true;
  while (cin >> n >> m >> q >> s) {
    if (n == 0 && m == 0 && q == 0 && s == 0) {
      break;
    }
    vector<vector<pair<int, int>>> adjList(n); // (wt, label)
    vector<tuple<int, int, int>> edgeList(m);  // (wt, label src, label dest)
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adjList[u].push_back(make_pair(w, v));
      edgeList[i] = make_tuple(w, u, v);
    }

    // bellman-ford
    vector<int> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        tuple<int, int, int> t = edgeList[j];
        int wt = get<0>(t);
        int u = get<1>(t);
        int v = get<2>(t);
        if (dist[u] != INF) {
          dist[v] = min(dist[v], dist[u] + wt);
        }
      }
    }

    /*
        for (int i = 0; i < n; i++) {
          cout << "i: " << i << " dist: " << dist[i] << endl;
        }
        */
    vector<bool> inNegCycle(n, false);
    for (int j = 0; j < m; j++) {
      tuple<int, int, int> t = edgeList[j];
      int wt = get<0>(t);
      int u = get<1>(t);
      int v = get<2>(t);
      // cout << "relaxing " << u << " -> " << v << " with wt " << wt << endl;
      if (dist[u] != INF && dist[u] + wt < dist[v]) {
        // cout << "can still relax " << v << endl;
        if (inNegCycle[v]) {
          continue;
        }
        inNegCycle[v] = true;
        queue<int> q;
        q.push(v);
        while (q.size() > 0) {
          int front = q.front();
          // cout << "poped" << front << endl;
          q.pop();
          for (int i = 0; i < adjList[front].size(); i++) {
            pair<int, int> p = adjList[front][i];
            int wt = p.first;
            int node = p.second;
            if (!inNegCycle[node]) {
              inNegCycle[node] = true;
              q.push(node);
            }
          }
        }
        // neg cycle detected
      }
    }

    if (isFirst) {
      isFirst = false;
    } else {
      cout << "\n";
    }

    while (q--) {
      int x;
      cin >> x;
      if (inNegCycle[x]) {
        cout << "-Infinity"
             << "\n";
      } else if (dist[x] == INF) {
        cout << "Impossible"
             << "\n";
      } else {
        cout << dist[x] << "\n";
      }
    }
  }
}