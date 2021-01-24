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
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

int encode(char c) {
  switch (c) {
  case '.':
    return 0;
  case 'P':
    return 1;
  case 'G':
    return 2;
  case 'T':
    return 3;
  case '#':
    return 4;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int w, h;
  cin >> w >> h;
  /*
    . - 0
    P - 1
    G - 2
    T - 3
    W - 4
  */
  vector<vector<int>> v(h, vector<int>(w));
  vector<vector<bool>> senseDraft(h, vector<bool>(w, false));
  int si, sj;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      v[i][j] = encode(c);
      if (v[i][j] == 1) {
        si = i;
        sj = j;
      } else if (v[i][j] == 3) {
        if (i - 1 >= 0)
          senseDraft[i - 1][j] = true;
        if (i + 1 < h)
          senseDraft[i + 1][j] = true;
        if (j - 1 >= 0)
          senseDraft[i][j - 1] = true;
        if (j + 1 < w)
          senseDraft[i][j + 1] = true;
      }
    }
  }

  vector<vector<bool>> seen(h, vector<bool>(w, false));
  seen[si][sj] = true;
  queue<pair<int, int>> q;
  q.push({si, sj});
  int res = 0;
  while (q.size() > 0) {
    auto [i, j] = q.front();
    q.pop();
    if (v[i][j] == 2) {
      res++;
    }
    if (senseDraft[i][j]) {
      continue;
    }
    if (i - 1 >= 0 && !seen[i - 1][j] && v[i][j] != 4) {
      seen[i - 1][j] = true;
      q.push({i - 1, j});
    }
    if (i + 1 < h && !seen[i + 1][j] && v[i][j] != 4) {
      seen[i + 1][j] = true;
      q.push({i + 1, j});
    }
    if (j - 1 >= 0 && !seen[i][j - 1] && v[i][j] != 4) {
      seen[i][j - 1] = true;
      q.push({i, j - 1});
    }
    if (j + 1 < w && !seen[i][j + 1] && v[i][j] != 4) {
      seen[i][j + 1] = true;
      q.push({i, j + 1});
    }
  }
  cout << res << '\n';
}
