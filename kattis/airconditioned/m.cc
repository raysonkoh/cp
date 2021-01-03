#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    v[i] = make_pair(l, r);
  }

  auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  };
  sort(v.begin(), v.end(), cmp);

  int currLo, currHi;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      res++;
      currLo = v[i].first;
      currHi = v[i].second;
    } else if ((currLo <= v[i].first && v[i].first <= currHi) || (currLo <= v[i].second && v[i].second <= currHi)) {
      // partial intersection
      currLo = max(currLo, v[i].first);
      currHi = min(currHi, v[i].second);
    } else {
      res++;
      currLo = v[i].first;
      currHi = v[i].second;
    }
  }
  cout << res << "\n";
}
