#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

const long long P = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

// 1. DFS
// 2. Reverse
// 3. DFS
// https://www.youtube.com/watch?v=Rs6DXyWpWrI&t=1s
class SCC {
public:
  vector<vector<int>> adjList;
  vector<vector<int>> revAdjList;
  vector<int> compId;
  vector<bool> visited;
  stack<int> stk;
  int n;
  SCC(vector<vector<int>> &adjList) : adjList(adjList), n(adjList.size()) {
    visited.assign(n, false);
    revAdjList.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
      for (int nei : adjList[i]) {
        revAdjList[nei].push_back(i);
      }
    }
    compId.assign(n, -1);
  }

  // first dfs to generate stk
  void dfs(int i) {
    visited[i] = true;
    for (int nei : adjList[i]) {
      if (visited[nei])
        continue;
      dfs(nei);
    }
    stk.push(i);
  }

  // second dfs to label scc id
  void dfs2(int i, int id) {
    visited[i] = true;
    compId[i] = id;
    for (int nei : revAdjList[i]) {
      if (visited[nei])
        continue;
      dfs2(nei, id);
    }
  }

  // return numSCCs
  int run() {
    for (int i = 0; i < n; i++) {
      if (visited[i])
        continue;
      dfs(i);
    }
    visited.assign(n, false);

    int currCompId = 0;
    while (stk.size() > 0) {
      int t = stk.top();
      stk.pop();
      if (!visited[t]) {
        dfs2(t, currCompId);
        currCompId++;
      }
    }

    return currCompId;
  }
};
