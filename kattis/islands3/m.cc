#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int r, c;
  cin >> r >> c;
  vector<vector<char>> v(r, vector<char>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }

  vector<vector<bool>> seen(r, vector<bool>(c, false));

  int res = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char ch = v[i][j];
      if (seen[i][j] || ch != 'L')
        continue;

      res++;
      queue<pair<int, int>> q;
      q.push({i, j});
      while (q.size() > 0) {
        auto [row, col] = q.front();
        q.pop();

        if (row - 1 >= 0 && !seen[row - 1][col]) {
          char tmp = v[row - 1][col];
          if (tmp == 'L' || tmp == 'C') {
            q.push({row - 1, col});
            seen[row - 1][col] = true;
          }
        }

        if (row + 1 < r && !seen[row + 1][col]) {
          char tmp = v[row + 1][col];
          if (tmp == 'L' || tmp == 'C') {
            q.push({row + 1, col});
            seen[row + 1][col] = true;
          }
        }

        if (col - 1 >= 0 && !seen[row][col - 1]) {
          char tmp = v[row][col - 1];
          if (tmp == 'L' || tmp == 'C') {
            q.push({row, col - 1});
            seen[row][col - 1] = true;
          }
        }

        if (col + 1 < c && !seen[row][col + 1]) {
          char tmp = v[row][col + 1];
          if (tmp == 'L' || tmp == 'C') {
            q.push({row, col + 1});
            seen[row][col + 1] = true;
          }
        }
      }
    }
  }
  cout << res << '\n';
}