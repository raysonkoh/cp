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

bool checkRows(vector<vector<bool>> &board) {
  for (int i = 0; i < board.size(); i++) {
    int b = 0, w = 0;
    for (auto x : board[i]) {
      if (x)
        b++;
      else
        w++;
    }
    if (b != w) return false;
  }
  return true;
}

bool checkCols(vector<vector<bool>> &board) {
  vector<int> colB(board.size(), 0);
  vector<int> colW(board.size(), 0);
  for (int i = 0; i < board.size(); i++) {
    int b = 0, w = 0;
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j])
        colB[j]++;
      else
        colW[j]++;
    }
  }

  for (int i = 0; i < colB.size(); i++) {
    if (colB[i] != colW[i]) return false;
  }
  return true;
}

bool checkConse(vector<vector<bool>> &board, vector<pair<int, int>> &blacks) {
  for (auto [i, j] : blacks) {
    if (j - 2 >= 0 && board[i][j - 2] && board[i][j - 1] && board[i][j]) return false;
    if (j + 2 < board.size() && board[i][j + 2] && board[i][j + 1] && board[i][j]) return false;
    if (i - 2 >= 0 && board[i - 2][j] && board[i - 1][j] && board[i][j]) return false;
    if (i + 2 < board.size() && board[i + 2][j] && board[i + 1][j] && board[i][j]) return false;
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
  vector<vector<bool>> board(n, vector<bool>(n));  // white - F, black - T
  vector<pair<int, int>> blacks;
  for (int i = 0; i < n; i++) {
    char c;
    for (int j = 0; j < n; j++) {
      cin >> c;
      board[i][j] = c == 'B';
      if (board[i][j]) blacks.push_back({i, j});
    }
  }
  if (checkRows(board) && checkCols(board) && checkConse(board, blacks))
    cout << 1 << '\n';
  else
    cout << 0 << '\n';
}
