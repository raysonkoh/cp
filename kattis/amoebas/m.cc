#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '#') {
        v[i][j] = 1;
      } else {
        v[i][j] = 0;
      }
    }
  }
  vector<vector<bool>> seen(n, vector<bool>(m, false));
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 1 && !seen[i][j]) {
        res++;
        seen[i][j] = true;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while (q.size() > 0) {
          pair<int, int> p = q.front();
          q.pop();

          // left upper diag
          if (p.second - 1 >= 0 && p.first - 1 >= 0 &&
              !seen[p.first - 1][p.second - 1] &&
              v[p.first - 1][p.second - 1] == 1) {
            seen[p.first - 1][p.second - 1] = true;
            q.push(make_pair(p.first - 1, p.second - 1));
          }
          // left lower diag
          if (p.second - 1 >= 0 && p.first + 1 < n &&
              !seen[p.first + 1][p.second - 1] &&
              v[p.first + 1][p.second - 1] == 1) {
            seen[p.first + 1][p.second - 1] = true;
            q.push(make_pair(p.first + 1, p.second - 1));
          }
          // right upper diag
          if (p.second + 1 < m && p.first - 1 >= 0 &&
              !seen[p.first - 1][p.second + 1] &&
              v[p.first - 1][p.second + 1] == 1) {
            seen[p.first - 1][p.second + 1] = true;
            q.push(make_pair(p.first - 1, p.second + 1));
          }
          // right lower diag
          if (p.second + 1 < m && p.first + 1 < n &&
              !seen[p.first + 1][p.second + 1] &&
              v[p.first + 1][p.second + 1] == 1) {
            seen[p.first + 1][p.second + 1] = true;
            q.push(make_pair(p.first + 1, p.second + 1));
          }
          // left
          if (p.second - 1 >= 0 && !seen[p.first][p.second - 1] &&
              v[p.first][p.second - 1] == 1) {
            seen[p.first][p.second - 1] = true;
            q.push(make_pair(p.first, p.second - 1));
          }
          // right
          if (p.second + 1 < m && !seen[p.first][p.second + 1] &&
              v[p.first][p.second + 1] == 1) {
            seen[p.first][p.second + 1] = true;
            q.push(make_pair(p.first, p.second + 1));
          }
          // up
          if (p.first - 1 >= 0 && !seen[p.first - 1][p.second] &&
              v[p.first - 1][p.second] == 1) {
            seen[p.first - 1][p.second] = true;
            q.push(make_pair(p.first - 1, p.second));
          }
          // down
          if (p.first + 1 < n && !seen[p.first + 1][p.second] &&
              v[p.first + 1][p.second] == 1) {
            seen[p.first + 1][p.second] = true;
            q.push(make_pair(p.first + 1, p.second));
          }
        }
      }
    }
  }
  cout << res << endl;
}