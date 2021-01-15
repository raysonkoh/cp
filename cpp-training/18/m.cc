#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11
#define LSOne(S) ((S) & -(S))

using namespace std;

class SegmentTree {
public:
  int n;
  vector<long long> vmin;  // actual value
  vector<long long> vmax;  // actual value
  vector<long long> vsum;  // actual value
  vector<long long> delta; // for lazy propagation
  vector<int> left;        // left boundary that node i is responsible up to
  vector<int> right;       // right boundary that node i is responsible up to

  SegmentTree(int n) {
    this->n = n;
    // <= 2n nodes for complete binary tree, * 2 for dummy nodes
    vmin.assign(4 * n + 1, 0);
    vmax.assign(4 * n + 1, 0);
    vsum.assign(4 * n + 1, 0);
    delta.assign(4 * n + 1, 0);
    left.assign(4 * n + 1, 0);
    right.assign(4 * n + 1, 0);

    // init left and right
    init(1, 0, n - 1);
  }

  void init(int i, int l, int r) {
    left[i] = l;
    right[i] = r;
    if (l == r) {
      // reached leaf node
      return;
    }
    int m = (l + r) / 2;
    init(i * 2, l, m);
    init(i * 2 + 1, m + 1, r);
  }

  void prop(int i) {
    delta[i * 2] += delta[i];
    delta[i * 2 + 1] += delta[i];
    delta[i] = 0;
  }

  // restore rep invariant
  void restoreRI(int i) {
    vsum[i] = vsum[i * 2] + delta[i * 2] + vsum[i * 2 + 1] + delta[i * 2 + 1];
    vmin[i] = min({vmin[i * 2] + delta[i * 2], vsum[i * 2] + delta[i * 2] + vmin[i * 2 + 1] + delta[i * 2 + 1], vsum[i], 0ll});
    vmax[i] = max({vmax[i * 2] + delta[i * 2], vsum[i * 2] + delta[i * 2] + vmax[i * 2 + 1] + delta[i * 2 + 1], vsum[i], 0ll});
  }

  void update(int l, int r, long long val) { update(1, l, r, val); }

  void update(int i, int l, int r, long long val) {
    // disjoint
    if (left[i] > r || right[i] < l) {
      return;
    }

    // total cover
    if (l <= left[i] && right[i] <= r) {
      delta[i] += val;
      return;
    }

    prop(i);
    update(i * 2, l, r, val);
    update(i * 2 + 1, l, r, val);
    restoreRI(i);
  }

  tuple<long long, long long, long long> query(int l, int r) { return query(1, l, r); } // (min, max, sum)

  tuple<long long, long long, long long> query(int i, int l, int r) {
    // disjoint
    if (left[i] > r || right[i] < l) {
      return {INT_MAX, INT_MIN, 0};
    }

    // total cover
    if (l <= left[i] && right[i] <= r) {
      return {vmin[i] + delta[i], vmax[i] + delta[i], vsum[i] + delta[i]};
    }

    prop(i);
    // auto [a1, b1, c1] = query(i * 2, l, r);
    // auto [a2, b2, c2] = query(i * 2 + 1, l, r);
    query(i * 2, l, r);
    query(i * 2 + 1, l, r);
    restoreRI(i);

    // return {min({a1, c1 + a2, c1 + c2, 0ll}), max({b1, c1 + b2, c1 + c2, 0ll}), c1 + c2};
    return {vmin[i], vmax[i], vsum[i]};
  }
};

int main() {
  SegmentTree st(4);
  st.update(0, 0, -1);
  st.update(1, 1, -1);
  st.update(2, 2, -1);
  st.update(3, 3, 1);
  auto [a, b, c] = st.query(1, 3);
  cout << a << endl; // -2
  cout << b << endl; // 0
  cout << c << endl; // -1
}
