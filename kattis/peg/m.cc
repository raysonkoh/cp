#include <algorithm>
#include <cassert>
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

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<vector<char>> board(7, vector<char>(7, ' '));
  queue<pair<int, int>> pos;
  string s;
  for (int i = 0; i < 7; i++) {
    getline(cin, s);
    if (i < 2 || i > 4) {
      for (int j = 2; j <= 4; j++) {
        board[i][j] = s.at(j);
        if (board[i][j] == '.') {
          // cout << "i: " << i << endl;
          // cout << "{" << i << ',' << j << "}\n";
          pos.push({i, j});
        }
      }
    } else {
      for (int j = 0; j < 7; j++) {
        board[i][j] = s.at(j);
        if (board[i][j] == '.') {
          // cout << "{" << i << ',' << j << "}\n";
          pos.push({i, j});
        }
      }
    }
  }

  int res = 0;
  while (pos.size() > 0) {
    auto [i, j] = pos.front();
    pos.pop();
    // i - 2, j
    res += (i - 2 >= 0 && board[i - 1][j] == 'o' && board[i - 2][j] == 'o');
    // i + 2, j
    res += (i + 2 < 7 && board[i + 1][j] == 'o' && board[i + 2][j] == 'o');
    // i, j - 2
    res += (j - 2 >= 0 && board[i][j - 1] == 'o' && board[i][j - 2] == 'o');
    // i, j + 2
    res += (j + 2 < 7 && board[i][j + 1] == 'o' && board[i][j + 2] == 'o');
  }
  cout << res << '\n';
}
