#include <algorithm>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  Ufds ufds(n);
  vector<tuple<int, int, int>> v(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      v[i * n + j] = make_tuple(x, i, j);
    }
  }
  sort(v.begin(), v.end());
  int count = 0;
  for (int i = 0; i < v.size(); i++) {
    tuple<int, int, int> t = v[i];
    int a = get<1>(t);
    int b = get<2>(t);
    if (!ufds.isSameSet(a, b)) {
      count++;
      ufds.mergeSet(a, b);
      cout << a + 1 << " " << b + 1 << "\n";
    }
    if (count == n - 1) {
      break;
    }
  }
}