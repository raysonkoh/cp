#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

// return true if i is in a cycle
bool dfs(int i, set<int> &seen, set<int> &stk, vector<vector<int>> &adjList) {
  seen.insert(i);
  stk.insert(i);
  bool ans = false;
  for (int nei : adjList[i]) {
    if (seen.count(nei) == 0) {
      ans = ans || dfs(nei, seen, stk, adjList);
    } else if (stk.count(nei) > 0) {
      ans = true;
    }
  }
  stk.erase(i);
  return ans;
}

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<string, int> smap;
  vector<pair<int, int>> edges(n);
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    if (smap.count(s1) == 0) {
      smap[s1] = smap.size();
    }
    if (smap.count(s2) == 0) {
      smap[s2] = smap.size();
    }
    edges[i] = {smap[s1], smap[s2]};
  }

  vector<vector<int>> adjList(smap.size(), vector<int>());
  for (auto [from, to] : edges) {
    adjList[from].push_back(to);
  }

  string ss;
  while (cin >> ss) {
    int indx = smap[ss];
    set<int> seen;
    set<int> stk;
    bool ans = dfs(indx, seen, stk, adjList);
    cout << ss << " ";
    cout << (ans ? "safe\n" : "trapped\n");
  }
}
