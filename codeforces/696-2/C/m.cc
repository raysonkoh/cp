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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(2 * n);
    map<int, int> notTaken;
    for (int i = 0; i < 2 * n; i++) {
      cin >> v[i];
      if (notTaken.count(v[i]) > 0) {
        notTaken[v[i]]++;
      } else {
        notTaken[v[i]] = 1;
      }
    }

    sort(v.begin(), v.end());
    bool can = false;
    for (int i = 0; i < v.size() - 1; i++) {
      int currMax = v[v.size() - 1];
      int x = v[i] + currMax;
      map<int, int> tmp = notTaken;
      vector<pair<int, int>> res;
      res.push_back({currMax, v[i]});
      auto eraseNum = [&](int num) {
        if (tmp[num] == 1) {
          tmp.erase(num);
        } else {
          tmp[num]--;
        }
      };
      eraseNum(currMax);
      eraseNum(v[i]);

      while (tmp.size() > 0) {
        x = currMax;
        currMax = prev(tmp.end())->first;
        int other = x - currMax;
        if (tmp.count(other) == 0) {
          break;
        } else {
          eraseNum(other);
          eraseNum(currMax);
          res.push_back({other, currMax});
        }
      }

      if (tmp.size() > 0) {
        continue;
      } else {
        can = true;
        cout << "YES\n";
        cout << v[i] + v[v.size() - 1] << '\n';
        for (auto [a, b] : res) {
          cout << a << " " << b << '\n';
        }
        break;
      }
    }
    if (!can) {
      cout << "NO" << '\n';
    }
  }
}
