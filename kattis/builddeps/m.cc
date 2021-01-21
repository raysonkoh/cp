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
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11
#define LSOne(S) ((S) & -(S))

using namespace std;

pair<string, int> getNextWord(string s, int st) {
  string res = "";
  for (int i = st; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ' ') {
      return make_pair(res, i);
    }
    res.push_back(c);
  }
  return make_pair(res, s.length());
}

void dfs(string curr, map<string, set<string>> &adjMap, set<string> &seen, deque<string> &dq) {
  seen.insert(curr);
  for (string nei : adjMap[curr]) {
    if (seen.count(nei) == 0)
      dfs(nei, adjMap, seen, dq);
  }

  dq.push_front(curr);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<string, set<string>> adjMap;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    auto [val, j] = getNextWord(s, 0);
    val = val.substr(0, val.length() - 1);
    while (j < s.length()) {
      auto [a, b] = getNextWord(s, j + 1);
      if (adjMap.count(a) == 0)
        adjMap[a] = set<string>();
      adjMap[a].insert(val);
      j = b;
    }
  }

  getline(cin, s);
  set<string> seen;
  deque<string> dq;
  dfs(s, adjMap, seen, dq);
  while (dq.size() > 0) {
    string tmp = dq.front();
    cout << tmp << '\n';
    dq.pop_front();
  }
}
