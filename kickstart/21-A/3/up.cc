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
  int caseNum = 1;
  while (t--) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    set<tuple<int, int, int>, greater<tuple<int, int, int>>> pq;  // (val, i, j), using SET as a MAXHEAP
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> mat[i][j];
        // cout << "i: " << i << " j: " << j << " val: " << mat[i][j] << endl;
        pq.insert({mat[i][j], i, j});
      }
    }

    long long res = 0;
    while (pq.size() > 0) {
      auto [val, i, j] = *pq.begin();
      // cout << "val: " << val << " i: " << i << " j: " << j << '\n';
      pq.erase(pq.begin());

      if (i - 1 >= 0 && abs(mat[i - 1][j] - val) > 1) {
        res += abs(mat[i - 1][j] - val) - 1;
        pq.erase(pq.find({mat[i - 1][j], i - 1, j}));
        mat[i - 1][j] = val - 1;
        pq.insert({mat[i - 1][j], i - 1, j});
      }

      if (i + 1 < r && abs(mat[i + 1][j] - val) > 1) {
        res += abs(mat[i + 1][j] - val) - 1;
        pq.erase(pq.find({mat[i + 1][j], i + 1, j}));
        mat[i + 1][j] = val - 1;
        pq.insert({mat[i + 1][j], i + 1, j});
      }

      if (j - 1 >= 0 && abs(mat[i][j - 1] - val) > 1) {
        res += abs(mat[i][j - 1] - val) - 1;
        pq.erase(pq.find({mat[i][j - 1], i, j - 1}));
        mat[i][j - 1] = val - 1;
        pq.insert({mat[i][j - 1], i, j - 1});
      }

      if (j + 1 < c && abs(mat[i][j + 1] - val) > 1) {
        res += abs(mat[i][j + 1] - val) - 1;
        pq.erase(pq.find({mat[i][j + 1], i, j + 1}));
        mat[i][j + 1] = val - 1;
        pq.insert({mat[i][j + 1], i, j + 1});
      }
    }

    cout << "Case #" << caseNum << ": " << res << '\n';
    caseNum++;
  }
}