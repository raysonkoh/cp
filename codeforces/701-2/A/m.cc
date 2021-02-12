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

int numIter(long long a, long long b) {
  int res = 0;
  while (a != 0) {
    a /= b;
    res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a == 0) {
      cout << 0 << '\n';
    } else if (b > a) {
      cout << 1 << '\n';
    } else if (b == a) {
      cout << 2 << '\n';
    } else {
      // a > b
      int res = 0;
      if (b == 1) {
        b++;
        res++;
      }

      int n = numIter(a, b);
      int n2 = numIter(a, b + 1);
      while (a != 0) {
        if (n2 < n) {
          b++;
        } else {
          a /= b;
        }
        res++;
        n = numIter(a, b);
        n2 = numIter(a, b + 1);
      }

      cout << res << '\n';
    }
  }
}
