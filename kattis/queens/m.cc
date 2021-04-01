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

bool vhor(int x, int y, vector<vector<bool>> &board) {
  for (int i = 0; i < board.size(); i++) {
    if (i == x) continue;
    if (board[y][i]) return false;
  }
  return true;
}

bool vver(int x, int y, vector<vector<bool>> &board) {
  for (int i = 0; i < board.size(); i++) {
    if (i == y) continue;
    if (board[i][x]) return false;
  }
  return true;
}

bool vldiag(int x, int y, vector<vector<bool>> &board) {
  int xx = x;
  int yy = y;
  while (xx - 1 >= 0 && yy + 1 < board.size()) {
    xx--;
    yy++;
  }

  while (true) {
    if (xx != x && yy != y) {
      if (board[yy][xx]) return false;
    }
    xx++;
    yy--;
    if (xx == board.size() || yy < 0) break;
  }

  return true;
}

bool vrdiag(int x, int y, vector<vector<bool>> &board) {
  int xx = x;
  int yy = y;
  while (xx + 1 < board.size() && yy + 1 < board.size()) {
    xx++;
    yy++;
  }

  while (true) {
    if (xx != x && yy != y) {
      if (board[yy][xx]) return false;
    }
    xx--;
    yy--;
    if (xx < 0 || yy < 0) break;
  }

  return true;
}

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
  int n;
  cin >> n;
  vector<vector<bool>> board(n, vector<bool>(n, false));
  vector<pair<int, int>> queens(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    queens[i] = {y, x};
    board[y][x] = true;
  }

  bool can = true;
  for (auto [y, x] : queens) {
    // cout << "hor: " << vhor(x, y, board) << endl;
    // cout << "ver: " << vver(x, y, board) << endl;
    // cout << "ldiag: " << vldiag(x, y, board) << endl;
    // cout << "rdiag: " << vrdiag(x, y, board) << endl;
    can = can && (vhor(x, y, board) && vver(x, y, board) && vldiag(x, y, board) && vrdiag(x, y, board));
    // cout << "x: " << x << " y: " << y << " can: " << can << endl;
  }

  cout << (can ? "CORRECT" : "INCORRECT") << '\n';
}
