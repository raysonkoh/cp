#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> money(n);
  for (int i = 0; i < n; i++) {
    cin >> money[i];
  }
  vector<vector<int>> adjList(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  queue<int> q;
  set<int> seen;
  int compId = 0;
  vector<vector<int>> components;
  for (int i = 0; i < n; i++) {
    if (seen.find(i) != seen.end()) {
      continue;
    }
    q.push(i);
    vector<int> tmp;
    while (q.size() > 0) {
      int next = q.front();
      q.pop();
      for (int j = 0; j < adjList[next].size(); j++) {
        int nei = adjList[next][j];
        if (seen.find(nei) == seen.end()) {
          seen.insert(nei);
          q.push(nei);
          tmp.push_back(nei);
        }
      }
    }
    components.push_back(tmp);
  }
  for (int i = 0; i < components.size(); i++) {
    int tol = 0;
    for (int j = 0; j < components[i].size(); j++) {
      tol += money[components[i][j]];
    }
    if (tol != 0) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  cout << "POSSIBLE" << endl;
}