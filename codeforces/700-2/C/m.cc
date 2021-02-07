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
  int n;
  cin >> n;
  int lo = 1;
  int hi = n;
  int a, b, c, res = -1;
  while (lo <= hi) {
    if (lo == hi) {
      res = lo;
      break;
    }
    int mid = lo + (hi - lo) / 2;
    if (mid - 1 >= 1) {
      cout << "? " << mid - 1 << '\n';
      cout.flush();
      cin >> a;
    } else {
      a = 1e9;
    }
    cout << "? " << mid << '\n';
    cout.flush();
    cin >> b;
    if (mid + 1 <= n) {
      cout << "? " << mid + 1 << '\n';
      cout.flush();
      cin >> c;
    } else {
      c = 1e9;
    }
    if (b < min(a, c)) {
      res = mid;
      break;
    } else if (b > a && c > a) {
      // continue on left
      hi = mid - 1;
    } else {
      // continue on right
      lo = mid + 1;
    }
  }
  cout << "! " << res << '\n';
}
