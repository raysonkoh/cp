#include <algorithm>
#include <climits>
#include <cmath>
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
const double EPS = 1e-11;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<string, int> strToIndx;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    strToIndx[s] = i;
    v[i] = s;
  }
  vector<vector<int>> adjList(n, vector<int>());
  int m;
  cin >> m;
  while (m--) {
    string a, b;
    cin >> a >> b;
    int ai = strToIndx[a];
    int bi = strToIndx[b];
    adjList[ai].push_back(bi);
    adjList[bi].push_back(ai);
  }

  bool can = true;
  vector<int> col(n, -1);
  set<int> seen;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (adjList[i].size() == 0)
      continue;
    if (seen.count(i) > 0)
      continue;

    q.push(i);
    seen.insert(i);
    col[i] = 1;
    while (q.size() > 0) {
      int nxt = q.front();
      int c = col[nxt];
      q.pop();
      int expect = (c + 1) % 2;
      for (int nei : adjList[nxt]) {
        if (col[nei] == -1 && seen.count(nei) == 0) {
          col[nei] = expect;
          q.push(nei);
          seen.insert(nei);
        } else if (col[nei] != expect) {
          can = false;
          break;
        }
      }

      if (!can)
        break;
    }
    if (!can)
      break;
  }

  if (!can)
    cout << "impossible\n";
  else {
    vector<string> s1;
    vector<string> s2;
    for (int i = 0; i < col.size(); i++) {
      if (col[i] == 0 || col[i] == -1) {
        s1.push_back(v[i]);
      } else {
        s2.push_back(v[i]);
      }
    }
    for (string x : s1) {
      cout << x << " ";
    }
    cout << '\n';
    for (string x : s2) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
