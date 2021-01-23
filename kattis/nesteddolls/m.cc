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
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    multiset<long long> widEndPoint;
    vector<pair<long long, long long>> hV(m);
    for (int i = 0; i < m; i++) {
      long long w, h;
      cin >> w >> h;
      hV[i] = {h, w};
    }

    sort(hV.begin(), hV.end(), [](pair<long long, long long> a, pair<long long, long long> b) {
      if (a.first == b.first) {
        return a.second > b.second;
      }
      return a.first < b.first;
    });

    for (int i = 0; i < m; i++) {
      auto [h, w] = hV[i];
      auto it = widEndPoint.lower_bound(w);
      if (it != widEndPoint.begin() && widEndPoint.size() > 0) {
        it = prev(it);
        // cout << "erase: " << *it << '\n';
        widEndPoint.erase(it);
      }
      widEndPoint.insert(w);
      // cout << "insert: " << w << '\n';
    }

    cout << widEndPoint.size() << '\n';
  }
}
