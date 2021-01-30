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
  while (t--) {
    int n, m;
    cin >> n >> m;
    int sx, sy;
    cin >> sx >> sy;
    sx--;
    sy--;
    vector<pair<int, int>> v;
    v.push_back({ sx, sy });
    vector<tuple<int, int, int, int, int>> edgeList; // (wt,sx,sy,dx,dy)
    int b;
    cin >> b;
    while (b--) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      for (auto [a, b] : v) {
        int dist = abs(a - x) + abs(b - y);
        edgeList.push_back({ dist, a, b, x, y });
        edgeList.push_back({ dist, x, y, a, b });
      }
      v.push_back({ x, y });
    }
    sort(edgeList.begin(), edgeList.end());
    }
}
