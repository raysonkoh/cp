#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long dfs(int i, int label, set<int> &visited,
              vector<vector<int>> &adjList) {
  // cout << "visiting: " << i << " label: " << label << endl;
  long long res = 0;

  for (int nei : adjList[i]) {
    bool isVisited = visited.find(nei) != visited.end();

    if (nei > label && !isVisited) {
      // cout << "ADD visiting: " << i << " nei: " << nei << endl;
      res++;
    }

    if (!isVisited) {
      visited.insert(nei);
      res += dfs(nei, label, visited, adjList);
      visited.erase(nei);
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> adjList(n + 1, vector<int>());
    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
      set<int> visited;
      visited.insert(i);
      res += dfs(i, i, visited, adjList);
    }
    cout << res << endl;
  }
}