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
    int n, m;
    cin >> n >> m;
    vector<long long> v(n);
    long long round = 0;
    long long maxDelta = -1e11;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      round += v[i];
      maxDelta = max(maxDelta, round);
    }

    while (m--) {
      long long x;
      cin >> x;
      if (v[0] >= x) {
        cout << 0 << " ";
        continue;
      }

      long long curr = 0;
      int res = -1;
      while (true) {
        if (curr + round <= curr)
          break;

        if (max(curr, curr + maxDelta) >= x) {
          if (curr >= x)
            break;

          for (int i = 0; i < n; i++) {
            curr += v[i];
            res++;
            if (curr >= x)
              break;
          }
          break;
        } else {
          long numRounds = x / round;
          curr += round * numRounds;
          res += n * numRounds;
        }
      }
      cout << (curr >= x ? res : -1) << " ";

      // round < 0 ?
      /*
      long long numRounds, tmp;
      int i, res;
      if (round <= 0) {
        numRounds = 0;
        tmp = v[0];
        res = 0;
        i = 1;
      } else {
        numRounds = x / round;
        tmp = numRounds * round;
        if (tmp >= x) {
        }
        res = numRounds * n - 1;
        i = 0;
      }

      cout << "tmp: " << tmp << endl;
      while (i < n && tmp < x) {
        tmp += v[i];
        i++;
        res++;
      }

      if (tmp >= x) {
        cout << res << " ";
      } else {
        cout << -1 << " ";
      }
    */
    }
    cout << '\n';
  }
}