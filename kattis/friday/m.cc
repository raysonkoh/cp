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

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int d, m;
    cin >> d >> m;
    int curr = 0;
    int res = 0;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      for (int j = 1; j <= x; j++) {
        if (curr == 5 && j == 13) {
          res++;
        }
        curr = (curr + 1) % 7;
      }
    }

    cout << res << '\n';
  }
}
