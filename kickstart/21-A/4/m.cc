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
  int caseNum = 1;
  /*
  Need spend min-cost to remove such "cycles"
  -1 -1
  -1 -1
  */
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<pair<long long, int>>> adjList(n, vector<pair<long long, int>>());  // (wt, label)
    vector<tuple<long long, int, int>> edgeList;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> A[i][j];
      }
    }

    vector<vector<int>> B(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        long long x;
        cin >> x;
        adjList[i].push_back({x, j});
        edgeList.push_back({x, i, n + j});
      }
    }

    sort(edgeList.rbegin(), edgeList.rend());
    Ufds ufds(n + n);
    long long res = 0;
    for (int i = 0; i < edgeList.size(); i++) {
      auto [val, ii, jj] = edgeList[i];
      // cout << "val: " << val << " ii: " << ii << " jj: " << jj << endl;
      if (ufds.isSameSet(ii, jj)) {
        res += val;
      } else {
        ufds.mergeSet(ii, jj);
      }
    }

    vector<int> cR(n);
    vector<int> cC(n);
    for (int i = 0; i < n; i++) {
      cin >> cR[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> cC[i];
    }

    cout << "Case #" << caseNum << ": " << res << '\n';
    caseNum++;
  }
}
