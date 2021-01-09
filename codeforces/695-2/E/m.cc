#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool dfs(int i, int par, vector<vector<int>> &adjList, vector<int> &A, set<int> &seen, set<int> &val) {
  seen.insert(i);
  val.insert(A[i]);

  for (int nei : adjList[i]) {
    if (nei == par || seen.count(nei) > 0)
      continue;

    if (val.count(A[nei]) > 0)
      return false;

    bool tmp = dfs(nei, i, adjList, A, seen, val);
    if (!tmp)
      return false;
  }

  val.erase(A[i]);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> adjList(n, vector<int>());
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    set<int> seen;
    set<int> val;
    bool tmp = dfs(i, -1, adjList, A, seen, val);
    if (tmp)
      res++;
  }
  cout << res << '\n';
}
