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
    int px, py;
    cin >> px >> py;
    string s;
    cin >> s;
    vector<int> v(4, 0);  // 0 - U, 1 - D, 2 - L, 3 - R
    for (char c : s) {
      if (c == 'U') {
        v[0]++;
      } else if (c == 'D') {
        v[1]++;
      } else if (c == 'L') {
        v[2]++;
      } else if (c == 'R') {
        v[3]++;
      }
    }
    bool can = true;
    if (px < 0) {
      can = can && (v[2] >= abs(px));
    } else {
      can = can && (v[3] >= px);
    }

    if (py < 0) {
      can = can && (v[1] >= abs(py));
    } else {
      can = can && (v[0] >= py);
    }
    cout << (can ? "YES" : "NO") << '\n';
  }
}
