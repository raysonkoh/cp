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
#include <stack>
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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    vector<int> b(n);
    vector<set<int>> mustChange(n + 1, set<int>());
    vector<set<int>> ct(n + 1, set<int>());
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (v[i] != b[i]) {
        mustChange[b[i]].insert(i);
      }
      ct[b[i]].insert(i);
    }

    vector<int> c(m);
    for (int i = 0; i < m; i++)
      cin >> c[i];

    vector<int> assign(m, -1);
    for (int i = 0; i < m; i++) {
      int curr = c[i];

      if (mustChange[curr].size() == 0 && ct[curr].size() == 0) {
        continue;
      }

      if (mustChange[curr].size() == 0) {
        assign[i] = *ct[curr].begin();
      } else {
        assign[i] = *mustChange[curr].begin();
        mustChange[curr].erase(mustChange[curr].begin());
      }
    }

    vector<int> suffixMax(m, -1);
    suffixMax[m - 1] = assign[m - 1];
    for (int i = m - 2; i >= 0; i--) {
      suffixMax[i] = max(suffixMax[i + 1], assign[i]);
    }

    /*
    cout << "assign: " << endl;
    for (auto x : assign)
      cout << x << " ";
    cout << endl;
    */

    bool can = true;
    for (int i = 0; i < m; i++) {
      if (assign[i] == -1) {
        if (suffixMax[i] == -1) {
          can = false;
          break;
        } else {
          assign[i] = suffixMax[i];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (mustChange[i + 1].size() > 0) {
        can = false;
        break;
      }
    }

    if (!can)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (auto x : assign)
        cout << x + 1 << " ";
      cout << '\n';
    }
  }
}
