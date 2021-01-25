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
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> countX(a + 1, 0);
    vector<int> countY(b + 1, 0);
    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      countX[x]++;
      v[i] = {x, 0};
    }
    for (int i = 0; i < k; i++) {
      int y;
      cin >> y;
      countY[y]++;
      v[i] = {v[i].first, y};
    }

    long long res = 0;
    for (auto [x, y] : v) {
      // cout << "x: " << x << " ct: " << countX[x] << endl;
      // cout << "y: " << y << " ct: " << countY[y] << endl;
      res += (k - countX[x] - countY[y] + 1);
    }
    cout << res / 2 << '\n';
  }
}