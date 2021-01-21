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
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    vector<long long> removeFront(n); // val of v[i] when all of v[0...i-1] are removed
    vector<long long> removeFrontMin(n);
    removeFront[0] = v[0];
    removeFrontMin[0] = v[0];
    for (int i = 1; i < n; i++) {
      removeFront[i] = v[i] - removeFront[i - 1];
      removeFrontMin[i] = min(removeFrontMin[i - 1], removeFront[i]);
    }
    if (removeFront[n - 1] == 0 && removeFrontMin[n - 1] >= 0) {
      // cout << 1 << endl;
      cout << "YES\n";
      continue;
    }

    vector<long long> removeBack(n); // val of v[i] when all of v[i+1...n-1] are removed
    vector<long long> removeBackMin(n);
    removeBack[n - 1] = v[n - 1];
    removeBackMin[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      removeBack[i] = v[i] - removeBack[i + 1];
      removeBackMin[i] = min(removeBackMin[i + 1], removeBack[i]);
    }

    /*
    cout << "removeFront: " << endl;
    for (auto x : removeFront) {
      cout << x << " ";
    }
    cout << endl;

    cout << "removeBack: " << endl;
    for (auto x : removeBack) {
      cout << x << " ";
    }
    cout << endl;
    */

    bool can = false;
    for (int i = 0; i < n - 1; i++) {
      // swap v[i] with v[i + 1]
      // check removeFront[i - 1], v[i + 1], v[i], removeBack[i + 2] is ok
      long long end, tmpMin;

      long long delta = v[i] - v[i + 1];
      if (i - 1 < 0 && i + 2 >= n) {
        end = delta;
        tmpMin = min({v[i + 1], end});
      } else if (i - 1 < 0) {
        end = removeBack[i + 2] - delta;
        tmpMin = min({v[i + 1], v[i] - v[i + 1], end, removeBackMin[i + 2]});
      } else if (i + 2 >= n) {
        end = delta + removeFront[i - 1];
        tmpMin = min({removeFrontMin[i - 1], removeFront[i - 1], v[i + 1] - removeFront[i - 1], end});
      } else {
        end = removeBack[i + 2] - delta - removeFront[i - 1];
        tmpMin = min({removeFrontMin[i - 1], removeFront[i - 1], v[i + 1] - removeFront[i - 1], v[i] - v[i + 1] + removeFront[i - 1], end, removeBackMin[i + 2]});
      }

      if (end == 0 && tmpMin >= 0) {
        // cout << "i: " << i << endl;
        can = true;
        cout << "YES\n";
        break;
      }
    }

    if (!can)
      cout << "NO\n";
  }
}
