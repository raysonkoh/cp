#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
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
const double EPS = 1e-9;

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

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m, c;
    cin >> m >> c;
    vector<tuple<int, int, int>> edgeList;  // (dist, i, j)
    int numIter = c * (c - 1) / 2;
    for (int i = 0; i < numIter; i++) {
      int a, b, d;
      cin >> a >> b >> d;
      edgeList.push_back({d, a, b});
    }
    sort(edgeList.begin(), edgeList.end());
    Ufds ufds(c);
    int wt = 0;
    for (auto tt : edgeList) {
      auto [d, a, b] = tt;
      // cout << "a: " << a << " b: " << b << " d: " << d << endl;
      if (!ufds.isSameSet(a, b)) {
        // cout << "merging " << a << " " << b << endl;
        ufds.mergeSet(a, b);
        wt += d;
      }
    }
    // cout << wt + c << endl;
    cout << (wt + c <= m ? "yes" : "no") << '\n';
  }
}
