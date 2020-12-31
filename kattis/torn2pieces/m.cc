#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<string, set<string>> adjList;
  string s;
  getline(cin, s);
  while (n--) {
    getline(cin, s);
    pair<string, int> p = getNextWord(s, 0);
    string key = p.first;
    adjList[key] = set<string>();
    while (p.second < s.length()) {
      pair<string, int> tmp = getNextWord(s, p.second + 1);
      adjList[key].insert(tmp.first);
      adjList[tmp.first].insert(key);
      p = tmp;
    }
  }

  getline(cin, s);
  pair<string, int> srcP = getNextWord(s, 0);
  pair<string, int> dstP = getNextWord(s, srcP.second + 1);
  queue<string> q;

  map<string, string> parent;
  parent[srcP.first] = "";
  q.push(srcP.first);
  while (q.size() > 0) {
    string node = q.front();
    // cout << "popped " << node << endl;
    q.pop();
    for (string nei : adjList[node]) {
      if (parent.find(nei) == parent.end()) {
        parent[nei] = node;
        q.push(nei);
      }
    }
  }
  // cout << srcP.first << " -> " << dstP.first << endl;

  if (parent.find(dstP.first) == parent.end()) {
    cout << "no route found\n";
  } else {
    string curr = dstP.first;
    vector<string> v = {curr};
    while (parent[curr] != "") {
      string par = parent[curr];
      v.push_back(par);
      curr = par;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      cout << v[i];
      if (i > 0) {
        cout << " ";
      }
    }
    cout << endl;
  }

  /*
  for (auto it : adjList) {
    cout << it.first << ": ";
    for (string nei : it.second) {
      cout << nei << " ";
    }
    cout << endl;
  }
  */
}