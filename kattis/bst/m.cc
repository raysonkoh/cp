#include <algorithm>
#include <cassert>
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

long long C = 0;

// Update and Query using 0-based indexing
class SegmentTree {
 public:
  int n;
  vector<long long> v;      // actual value
  vector<long long> delta;  // for lazy propagation
  vector<int> left;         // left boundary that node i is responsible up to
  vector<int> right;        // right boundary that node i is responsible up to

  SegmentTree(int n) {
    this->n = n;
    // <= 2n nodes for complete binary tree, * 2 for dummy nodes
    v.assign(4 * n + 1, 0);
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
  void restoreRI(int i) { v[i] = v[i * 2] + delta[i * 2] + v[i * 2 + 1] + delta[i * 2 + 1]; }

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

  long long query(int l, int r) { return query(1, l, r); }

  long long query(int i, int l, int r) {
    // disjoint
    if (left[i] > r || right[i] < l) {
      return 0;
    }

    // total cover
    if (l <= left[i] && right[i] <= r) {
      return v[i] + delta[i];
    }

    prop(i);
    long long sumLeft = query(i * 2, l, r);
    long long sumRight = query(i * 2 + 1, l, r);
    restoreRI(i);

    return sumLeft + sumRight;
  }
};

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  SegmentTree st(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    v[i] = x;
  }

  set<int> nums;
  for (int i = 0; i < n; i++) {
    int x = v[i];
    long long d = st.query(x, x);
    C += d;
    cout << C << '\n';
    int lo, hi;
    if (nums.size() == 0) {
      lo = 0;
      hi = n - 1;
    } else {
      auto itHi = nums.lower_bound(x);
      if (itHi == nums.end())
        hi = n - 1;
      else
        hi = *itHi;
      if (itHi == nums.begin())
        lo = 0;
      else
        lo = *prev(itHi);
    }
    st.update(lo, x - 1, 1);
    st.update(x + 1, hi, 1);
    nums.insert(x);
  }
}
