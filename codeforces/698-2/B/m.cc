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
    int q, d;
    cin >> q >> d;
    for (int i = 0; i < q; i++) {
      int x;
      cin >> x;
      if (to_string(x).find(to_string(d)) != -1) {
        cout << "YES\n";
      } else {
        int quot = x / d;
        int remain = x % d;
        bool can = false;
        for (int j = 1; j < quot; j++) {
          if (to_string(remain + d * j).find(to_string(d)) != -1) {
            can = true;
            cout << "YES\n";
            break;
          }
        }
        if (!can)
          cout << "NO\n";
      }
    }
  }
}
