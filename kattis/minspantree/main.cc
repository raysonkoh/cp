#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Ufds {
public:
  vector<int> rank;
  vector<int> parent;
  Ufds(int n) {
    rank.assign(n, 0);
    parent.assign(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int findCompId(int x) {
    int tmp = x;
    while (parent[tmp] != tmp) {
      tmp = parent[tmp];
    }
    return tmp;
  }
  bool isSameSet(int a, int b) { return findCompId(a) == findCompId(b); }
  void unionSet(int a, int b) {
    int aid = findCompId(a);
    int bid = findCompId(b);
    if (aid == bid) {
      return;
    }
    if (rank[bid] > rank[aid]) {
      swap(aid, bid);
    }
    // bid join to aid
    parent[bid] = aid;
    if (rank[bid] == rank[aid]) {
      rank[aid]++;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    Ufds ufds(n);
    vector<tuple<int, int, int>> edgeList(m);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      if (u > v) {
        swap(u, v);
      }
      edgeList[i] = make_tuple(w, u, v);
    }
    sort(edgeList.begin(), edgeList.end());
    vector<pair<int, int>> chosenEdges;
    int cost = 0;
    for (int i = 0; i < m; i++) {
      tuple<int, int, int> t = edgeList[i];
      int u = get<1>(t);
      int v = get<2>(t);
      if (!ufds.isSameSet(u, v)) {
        cost += get<0>(t);
        chosenEdges.push_back(make_pair(u, v));
        ufds.unionSet(u, v);
      }
    }
    if (chosenEdges.size() == n - 1) {
      sort(chosenEdges.begin(), chosenEdges.end());
      cout << cost << endl;
      for (int i = 0; i < n - 1; i++) {
        cout << chosenEdges[i].first << " " << chosenEdges[i].second << endl;
      }
    } else {
      cout << "Impossible" << endl;
    }
  }
}