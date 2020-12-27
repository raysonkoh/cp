#include <iostream>
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