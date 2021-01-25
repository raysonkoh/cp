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
    int n;
    cin >> n;
    // only first row can flip column
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        v[i][j] = c - '0';
      }
    }
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        res[i][j] = c - '0';
      }
    }

    vector<int> colOffset(n, 0);
    bool can = true;
    for (int i = 0; i < n; i++) {
      int offset = 0;
      for (int j = 0; j < n; j++) {
        int curr = (v[i][j] + offset + colOffset[j]) % 2;
        int expect = res[i][j];
        if (curr == expect)
          continue;

        if (j == 0) {
          offset++;
        } else if (i == 0) {
          colOffset[j]++;
        } else {
          can = false;
          cout << "NO\n";
          break;
        }
      }
      if (!can)
        break;
    }

    if (can)
      cout << "YES\n";
  }
}