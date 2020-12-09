#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int INF = 10000000;

int main() {
  int n, m, q, s;
  bool isFirst = true;
  while (cin >> n >> m >> q >> s) {
    if (n == 0 && m == 0 && q == 0 && s == 0) {
      break;
    }

    if (isFirst) {
      isFirst = false;
    } else {
      cout << endl;
    }

    // [wt, nei_vertex]
    map<int, vector<pair<int, int>>> adjList;
    map<int, int> res; // [no. -> wt]
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 0; i < n; i++) {
      vector<pair<int, int>> tmp;
      adjList[i] = tmp;
      if (i == s) {
        pq.push(make_pair(0, i));
        res[i] = 0;
      } else {
        pq.push(make_pair(INF, i));
        res[i] = INF;
      }
    }

    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adjList[u].push_back(make_pair(w, v));
    }

    while (pq.size() > 0) {
      pair<int, int> next = pq.top();
      // cout << next.first << " " << next.second << endl;
      pq.pop();

      // VERY IMPORTANT OPTIMIZATION!!!!
      if (res.find(next.second)->second < next.first) {
        continue;
      }

      vector<pair<int, int>> neis = adjList.find(next.second)->second;
      for (int i = 0; i < neis.size(); i++) {
        int nei = neis[i].second;
        // cout << "nei: " << nei << endl;
        int wt = neis[i].first;
        // cout << next.first + wt << " : " << res.find(nei)->second << endl;
        if (next.first + wt < res.find(nei)->second) {
          res[nei] = next.first + wt;
          pq.push(make_pair(next.first + wt, nei));
        }
      }
    }

    for (int i = 0; i < q; i++) {
      int x;
      cin >> x;
      // cout << x << " ";
      int val = res.find(x)->second;
      if (val == INF) {
        cout << "Impossible" << endl;
      } else {
        cout << res.find(x)->second << endl;
      }
    }
  }
  return 0;
}