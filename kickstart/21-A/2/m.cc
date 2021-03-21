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

int calc(int x, int y) {
  return min(2 * x, y) / 2 - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  int caseNum = 1;
  while (t--) {
    int r, c;
    cin >> r >> c;
    vector<vector<bool>> v(r, vector<bool>(c));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int x;
        cin >> x;
        v[i][j] = x == 1;
      }
    }

    // [i][j] entry indicates num of consecutive up/down/left/right 1s
    vector<vector<int>> up(r, vector<int>(c, 0));
    vector<vector<int>> down(r, vector<int>(c, 0));
    vector<vector<int>> left(r, vector<int>(c, 0));
    vector<vector<int>> right(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        up[i][j] += v[i][j];
        left[i][j] += v[i][j];
        if (up[i][j] && i - 1 >= 0)
          up[i][j] += up[i - 1][j];
        if (left[i][j] && j - 1 >= 0)
          left[i][j] += left[i][j - 1];
      }
    }

    for (int i = r - 1; i >= 0; i--) {
      for (int j = c - 1; j >= 0; j--) {
        down[i][j] += v[i][j];
        right[i][j] += v[i][j];
        if (down[i][j] && i + 1 < r)
          down[i][j] += down[i + 1][j];
        if (right[i][j] && j + 1 < c)
          right[i][j] += right[i][j + 1];
      }
    }

    long long res = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (!v[i][j])
          continue;

        int xLeftLen = left[i][j];
        int xRightLen = right[i][j];
        int yUpLen = up[i][j];
        int yDownLen = down[i][j];

        // cout << "i: " << i << " j: " << j << " yUpLen: " << yUpLen << " yDownLen: " << yDownLen << " xLeftLen: " << xLeftLen << " xRightLen: " << xRightLen << '\n';

        if (yUpLen >= 2 && xLeftLen >= 2) {
          res += calc(yUpLen, xLeftLen);
          res += calc(xLeftLen, yUpLen);
        }

        if (yDownLen >= 2 && xLeftLen >= 2) {
          res += calc(xLeftLen, yDownLen);
          res += calc(yDownLen, xLeftLen);
        }

        if (yDownLen >= 2 && xRightLen >= 2) {
          res += calc(yDownLen, xRightLen);
          res += calc(xRightLen, yDownLen);
        }

        if (yUpLen >= 2 && xRightLen >= 2) {
          res += calc(xRightLen, yUpLen);
          res += calc(yUpLen, xRightLen);
        }
      }
    }

    cout << "Case #" << caseNum << ": " << res << '\n';
    caseNum++;
  }
}