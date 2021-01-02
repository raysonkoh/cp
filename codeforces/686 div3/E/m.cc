#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Ufds {
public:
  vector<int> parent;
  vector<int> size;
  Ufds(int n) {
    parent.assign(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
    size.assign(n, 1);
  }

  int findCompId(int x) {
    while (parent[x] != x) {
      x = parent[x];
    }
    return x;
  }

  bool isSameSet(int a, int b) { return findCompId(a) == findCompId(b); }

  int getSize(int x) {
    int compId = findCompId(x);
    return size[compId];
  }

  void mergeSet(int a, int b) {
    if (isSameSet(a, b)) {
      return;
    }
    int aid = findCompId(a);
    int bid = findCompId(b);
    if (size[aid] > size[bid]) {
      swap(aid, bid);
    }

    parent[aid] = bid;
    size[bid] += size[aid];
  }
};

// find cyclic nodes
void dfs(int node, int parent, vector<vector<int>> &adjList, vector<bool> &visited, stack<int> &stk, vector<bool> &inCycle) {
  visited[node] = true;
  stk.push(node);

  for (int nei : adjList[node]) {
    if (nei == parent)
      continue;

    if (!visited[nei]) {
      dfs(nei, node, adjList, visited, stk, inCycle);
      if (inCycle[nei]) {
        return;
      }
    } else if (!inCycle[nei]) {
      inCycle[nei] = true;

      while (stk.top() != nei) {
        int tmp = stk.top();
        stk.pop();
        inCycle[tmp] = true;
      }
      return;
    } else {
      return;
    }
  }

  stk.pop();
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

    vector<bool> visited(n + 1, false);
    stack<int> stk;
    vector<bool> inCycle(n + 1, false);
    dfs(1, 0, adjList, visited, stk, inCycle);

    Ufds ufds(n);
    for (int i = 1; i < adjList.size(); i++) {
      for (int j : adjList[i]) {
        if (inCycle[i] && inCycle[j]) {
          continue;
        }

        ufds.mergeSet(i - 1, j - 1);
      }
    }
    vector<long long> ct;
    for (int i = 1; i < inCycle.size(); i++) {
      if (inCycle[i]) {
        ct.push_back(ufds.getSize(i - 1));
      }
    }

    long long res = 0;
    for (long long count : ct) {
      res += count * (count - 1) / 2; // within same tree
      res += count * (n - count);     // to other tree
    }
    cout << res << endl;
  }
}
