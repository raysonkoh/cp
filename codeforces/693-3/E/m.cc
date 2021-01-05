#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> h(n);
    vector<long long> w(n);
    map<long long, pair<long long, int>> htToMinW; // (ht, (minW, label))

    for (int i = 0; i < n; i++) {
      cin >> h[i];
      cin >> w[i];
      if (htToMinW.find(h[i]) == htToMinW.end()) {
        htToMinW[h[i]] = {w[i], i};
      } else if (w[i] < htToMinW[h[i]].first) {
        htToMinW[h[i]] = {w[i], i};
      }
    }

    for (auto it = next(htToMinW.begin()); it != htToMinW.end(); it++) {
      auto pre = prev(it);
      it->second = min(it->second, pre->second);
    }

    vector<int> v(n, -1);
    for (int i = 0; i < n; i++) {
      long long ht = h[i];
      long long wd = w[i];

      // case 1 hj < hi && wj < wi
      auto it1 = htToMinW.lower_bound(ht);
      if (it1 != htToMinW.begin()) {
        it1 = prev(it1);
        if (it1->second.first < wd) {
          v[i] = it1->second.second + 1;
          continue;
        }
      }

      // case 2 wj < hi && hj < wi
      auto it2 = htToMinW.lower_bound(wd);
      if (it2 != htToMinW.begin()) {
        it2 = prev(it2);
        if (it2->second.first < ht) {
          v[i] = it2->second.second + 1;
        }
      }
    }

    bool isFirst = true;
    for (int i : v) {
      if (isFirst)
        isFirst = false;
      else
        cout << " ";
      cout << i;
    }
    cout << "\n";
  }
}