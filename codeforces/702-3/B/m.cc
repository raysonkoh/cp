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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ct(3, 0);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      ct[v[i] % 3]++;
    }

    int expectPer = n / 3;
    int res = 0;
    for (int k = 0; k < 10; k++) {
      bool can = true;
      for (int i = 0; i < 3; i++) {
        if (ct[i] == expectPer)
          continue;
        else if (ct[i] < expectPer) {
          can = false;
          continue;
        }

        can = false;
        int noNeed = ct[i] - expectPer;
        ct[i] = expectPer;
        ct[(i + 1) % 3] += noNeed;
        res += noNeed;
      }

      if (can)
        break;
    }
    cout << res << '\n';
  }
}
