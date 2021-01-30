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
  vector<vector<bool>> isWhite(8, vector<bool>(8));
  bool first = true;
  for (int i = 0; i < isWhite.size(); i++) {
    for (int j = 0; j < isWhite[i].size(); j++) {
      if (j == 0) {
        isWhite[i][j] = first;
      } else {
        isWhite[i][j] = !isWhite[i][j - 1];
      }
    }
    first = !first;
  }
  auto canReach = [&](int si, int sj, int di, int dj) {
    int xoff = di - si;
    int yoff = dj - sj;
    return (abs(xoff) == abs(yoff));
  };

  int t;
  cin >> t;
  while (t--) {
    char ch1, ch2;
    int r1, r2;
    cin >> ch1 >> r1 >> ch2 >> r2;
    int c1 = ch1 - 'A';
    int c2 = ch2 - 'A';
    r1 = 8 - r1;
    r2 = 8 - r2;
    if (isWhite[r1][c1] != isWhite[r2][c2]) {
      cout << "Impossible\n";
    } else {
      queue<pair<int, int>> q;
      vector<vector<int>> ct(8, vector<int>(8, 1e9));
      vector<vector<pair<int, int>>> par(8, vector<pair<int, int>>(8, { -1, -1 }));
      q.push({ r1, c1 });
      ct[r1][c1] = 0;
      while (q.size() > 0) {
        auto [r, c] = q.front();
        // cout << "r: " << r << " c: " << c << endl;
        q.pop();
        for (int i = 0; i < 8; i++) {
          for (int j = 0; j < 8; j++) {
            if (canReach(r, c, i, j) && (par[i][j] == make_pair(-1, -1) && !(i == r1 && j == c1))) {
              q.push({ i, j });
              // cout << "pushing i: " << i << " j: " << j << '\n';
              par[i][j] = { r, c };
              ct[i][j] = ct[r][c] + 1;
            }
          }
        }
      }

      cout << ct[r2][c2] << ' ';
      vector<pair<int, int>> res;
      pair<int, int> currP = { r2, c2 };
      while (currP != make_pair(-1, -1)) {
        res.push_back(currP);
        currP = par[currP.first][currP.second];
      }
      for (int i = res.size() - 1; i >= 0; i--) {
        cout << (char)(res[i].second + 'A') << " " << 8 - res[i].first << " ";
      }
      cout << '\n';
    }
  }
}
