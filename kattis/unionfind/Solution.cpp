#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
  int parent[1000000];
  int size[1000000];

  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findCompId(int x) {
    while (parent[x] != x) {
      x = parent[x];
    }
    return x;
  }

  bool isSameSet(int p, int q) { return findCompId(p) == findCompId(q); }

  void unionSet(int p, int q) {
    int pid = findCompId(p);
    int qid = findCompId(q);
    if (pid == qid) {
      return;
    }
    if (size[pid] > size[qid]) {
      swap(pid, qid);
    }
    parent[pid] = qid;
    size[qid] += size[pid];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, q;
  cin >> n >> q;
  UnionFind ufds(n);

  string s;
  int a, b;

  for (int i = 0; i < q; i++) {
    cin >> s >> a >> b;
    if (s == "=") {
      // union
      ufds.unionSet(a, b);
    } else {
      // find
      bool res = ufds.isSameSet(a, b);
      if (res) {
        cout << "yes"
             << "\n";
      } else {
        cout << "no"
             << "\n";
      }
    }
  }

  return 0;
}