#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
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
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int l, m;
    cin >> l >> m;
    queue<int> left;
    queue<int> right;
    for (int i = 0; i < m; i++) {
      int len;
      string dir;
      cin >> len >> dir;
      if (dir == "left") {
        left.push(len);
      } else {
        right.push(len);
      }
    }

    int pos = 0;  // 0 - left, 1 - right
    int ans = 0;
    while (left.size() > 0 || right.size() > 0) {
      int tmp = l * 100;
      if (pos == 0) {
        while (left.size() > 0 && tmp - left.front() >= 0) {
          tmp -= left.front();
          left.pop();
        }
      } else {
        while (right.size() > 0 && tmp - right.front() >= 0) {
          tmp -= right.front();
          right.pop();
        }
      }

      pos = 1 - pos;
      ans++;
    }
    cout << ans << '\n';
  }
}
