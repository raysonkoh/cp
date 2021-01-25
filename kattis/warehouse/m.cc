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
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
      string s;
      int x;
      cin >> s >> x;
      if (m.count(s) == 0)
        m[s] = 0;
      m[s] += x;
    }

    vector<pair<string, int>> v;
    for (auto p : m) {
      v.push_back(p);
    }
    sort(v.begin(), v.end(), [](pair<string, int> p1, pair<string, int> p2) {
      if (p1.second == p2.second)
        return p1.first < p2.first;
      return p1.second > p2.second;
    });

    cout << v.size() << '\n';
    for (auto [key, val] : v) {
      cout << key << " " << val << '\n';
    }
  }
}
