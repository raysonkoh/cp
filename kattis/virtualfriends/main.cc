#include <iostream>
#include <map>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int f;
    cin >> f;
    map<string, int> m;
    vector<pair<string, string>> v(f);
    int currIndx = 0;
    for (int j = 0; j < f; j++) {
      string a, b;
      cin >> a >> b;
      if (m.find(a) == m.end()) {
        m[a] = currIndx;
        currIndx++;
      }
      if (m.find(b) == m.end()) {
        m[b] = currIndx;
        currIndx++;
      }
      v[j] = make_pair(a, b);
    }

    Ufds ufds(currIndx);
    for (int j = 0; j < f; j++) {
      pair<string, string> p = v[j];
      int aIndx = m[p.first];
      int bIndx = m[p.second];
      ufds.mergeSet(aIndx, bIndx);
      cout << ufds.size[ufds.findCompId(aIndx)] << endl;
    }
  }
}