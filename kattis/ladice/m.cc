#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Ufds {
public:
  vector<int> parent;
  vector<int> size;
  vector<int> incrCount;
  Ufds(int n) {
    parent.assign(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
    size.assign(n, 1);
    incrCount.assign(n, 0);
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
    incrCount[bid] += incrCount[aid];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, l;
  cin >> n >> l;

  Ufds ufds(l + 1);

  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    ufds.mergeSet(a, b);
    int compId = ufds.findCompId(a);
    if (ufds.incrCount[compId] + 1 <= ufds.size[compId]) {
      ufds.incrCount[compId]++;
      cout << "LADICA\n";
    } else {
      cout << "SMECE\n";
    }
  }
}
