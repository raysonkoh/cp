#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class SegmentTree {
public:
  int n;
  vector<long long> v;     // actual value
  vector<long long> delta; // for lazy propagation
  vector<int> left;        // left boundary that node i is responsible up to
  vector<int> right;       // right boundary that node i is responsible up to

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
  void restoreRI(int i) { v[i] = min(v[i * 2] + delta[i * 2], v[i * 2 + 1] + delta[i * 2 + 1]); }

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
      return INT_MAX;
    }

    // total cover
    if (l <= left[i] && right[i] <= r) {
      return v[i] + delta[i];
    }

    prop(i);
    long long minLeft = query(i * 2, l, r);
    long long minRight = query(i * 2 + 1, l, r);
    restoreRI(i);

    return min(minLeft, minRight);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> runningMax(n);
    vector<int> runningMaxFromEnd(n);
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
      if (i == 0) {
        runningMax[i] = x;
      } else {
        runningMax[i] = max(runningMax[i - 1], x);
      }
      st.update(i, i, x);
    }

    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) {
        runningMaxFromEnd[i] = v[i];
      } else {
        runningMaxFromEnd[i] = max(runningMaxFromEnd[i + 1], v[i]);
      }
    }

    bool isFound = false;
    for (int i = 0; i < n - 2; i++) {
      int beginMax = runningMax[i];

      int lo = i + 2;
      int hi = n - 1;

      // cout << "i: " << i << " range: " << lo << ", " << hi << endl;
      while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (runningMaxFromEnd[m] < beginMax) {
          // move left
          hi = m - 1;
        } else if (runningMaxFromEnd[m] > beginMax) {
          // move right
          lo = m + 1;
        } else {
          int tmp = st.query(i + 1, m - 1);
          if (tmp == beginMax) {
            isFound = true;
            cout << "YES\n";
            int a = i + 1;
            int b = m - a;
            int c = n - a - b;
            cout << a << " " << b << " " << c << "\n";
            break;
          } else if (tmp < beginMax) {
            // move left
            hi = m - 1;
          } else {
            // move right
            lo = m + 1;
          }
        }
      }

      if (isFound) {
        break;
      }
    }

    if (!isFound) {
      cout << "NO\n";
    }
  }
}
