#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi) {
    if (lo == hi) {
      cout << lo + 1 << endl;
      break;
    }
    int m = lo + (hi - lo) / 2;
    // cout << lo << " " << hi << " " << m << endl;
    if (m == n - 1) {
      hi = m;
    } else if (v[m] + v[m + 1] > x) {
      // move left
      hi = m;
    } else {
      // move right
      lo = m + 1;
    }
  }
}