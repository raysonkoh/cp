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
    for (int i = 0; i < n; i++)
      cin >> v[i];
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
      int a = v[i];
      int b = v[i + 1];
      int maxx = max(a, b);
      int minn = min(a, b);
      if (maxx <= 2 * minn) {
        continue;
      }

      int tmp = minn;
      while (maxx > 2 * tmp) {
        res++;
        tmp = 2 * tmp;
      }
    }
    cout << res << '\n';
  }
}
