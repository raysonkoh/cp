#include <climits>
#include <iostream>
#include <vector>

using namespace std;

template <class T> void print(vector<T> &v) {
  for (T x : v) {
    cout << x << " ";
  }
  cout << endl;
}

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
  void restoreRI(int i) {
    v[i] = min(v[i * 2] + delta[i * 2], v[i * 2 + 1] + delta[i * 2 + 1]);
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

vector<long long> extractInts(string s) {
  vector<long long> res;
  string tmp = "";
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ' ') {
      res.push_back(stoll(tmp));
      tmp = "";
    } else {
      tmp.push_back(c);
    }
  }
  res.push_back(stoll(tmp));
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  SegmentTree st(n);
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    st.update(i, i, x);
  }

  int m;
  cin >> m;
  string s;

  getline(cin, s);
  while (m--) {
    getline(cin, s);
    vector<long long> v = extractInts(s);
    if (v.size() == 2) {
      // rmq
      long long l = v[0];
      long long r = v[1];
      if (l <= r) {
        cout << st.query(l, r) << "\n";
      } else {
        cout << min(st.query(l, n - 1), st.query(0, r)) << "\n";
      }
    } else {
      // inc
      long long l = v[0];
      long long r = v[1];
      long long val = v[2];
      if (l <= r) {
        st.update(l, r, val);
      } else {
        st.update(l, n - 1, val);
        st.update(0, r, val);
      }
    }
  }
}