#include <algorithm>
#include <cassert>
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

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    bool can = false;
    for (long long a = 1; a <= 1e4 + 10; a++) {
      long long acube = a * a * a;
      long long diff = x - acube;
      if (diff <= 0)
        continue;

      long long b = cbrt(diff);
      if (b * b * b == diff) {
        can = true;
        break;
      }
    }
    cout << (can ? "YES" : "NO") << '\n';
  }
}
