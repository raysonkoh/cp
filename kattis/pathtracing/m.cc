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
  vector<vector<char>> board(1010, vector<char>(1010, ' '));

  int i = 505, j = 505;
  board[i][j] = 'S';
  string s;
  while (cin >> s) {
    if (s == "left") {
      j--;
    } else if (s == "right") {
      j++;
    } else if (s == "up") {
      i--;
    } else if (s == "down") {
      i++;
    }
    if (board[i][j] == ' ') board[i][j] = '*';
  }
  board[i][j] = 'E';

  int lj = 0;
  int rj = 1009;
  for (; lj < 1010; lj++) {
    bool can = true;
    for (int ii = 0; ii < 1010; ii++) {
      if (board[ii][lj] != ' ') {
        can = false;
        break;
      }
    }
    if (!can) break;
  }

  for (; rj >= 0; rj--) {
    bool can = true;
    for (int ii = 0; ii < 1010; ii++) {
      if (board[ii][rj] != ' ') {
        can = false;
        break;
      }
    }
    if (!can) break;
  }

  int ui = 0;
  int di = 1009;
  for (; ui < 1010; ui++) {
    bool can = true;
    for (int jj = 0; jj < 1010; jj++) {
      if (board[ui][jj] != ' ') {
        can = false;
        break;
      }
    }
    if (!can) break;
  }

  for (; di >= 0; di--) {
    bool can = true;
    for (int jj = 0; jj < 1010; jj++) {
      if (board[di][jj] != ' ') {
        can = false;
        break;
      }
    }
    if (!can) break;
  }

  lj--;
  rj++;
  ui--;
  di++;
  // cout << "lj: " << lj << " rj: " << rj << " ui: " << ui << " di: " << di << endl;

  for (int ii = ui; ii <= di; ii++) {
    for (int jj = lj; jj <= rj; jj++) {
      if (ii == ui || ii == di || jj == lj || jj == rj) {
        cout << '#';
      } else {
        cout << board[ii][jj];
      }
    }
    cout << '\n';
  }
}
