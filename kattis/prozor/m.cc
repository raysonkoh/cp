#include <iostream>
#include <vector>

#define P 1000000007

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int r, s, k;
  cin >> r >> s >> k;
  vector<vector<char>> v(r, vector<char>(s));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < s; j++) {
      cin >> v[i][j];
    }
  }
  auto countFlies = [&](pair<int, int> p) {
    auto [row, col] = p;
    int res = 0;
    for (int i = row + 1; i < row + k - 1; i++) {
      for (int j = col + 1; j < col + k - 1; j++) {
        res += (v[i][j] == '*');
      }
    }
    return res;
  };

  pair<int, int> bestP = {-1, -1};
  int best = 0;
  for (int i = 0; i <= r - k; i++) {
    for (int j = 0; j <= s - k; j++) {
      int tmp = countFlies({i, j});
      if (tmp > best) {
        bestP = {i, j};
        best = tmp;
      }
    }
  }

  for (int i = bestP.first; i < bestP.first + k; i++) {
    for (int j = bestP.second; j < bestP.second + k; j++) {
      if (i == bestP.first || i == bestP.first + k - 1) {
        if (j == bestP.second || j == bestP.second + k - 1) {
          v[i][j] = '+';
        } else {
          v[i][j] = '-';
        }
      } else if (j == bestP.second || j == bestP.second + k - 1) {
        v[i][j] = '|';
      }
    }
  }
  cout << best << "\n";
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < s; j++) {
      cout << v[i][j];
    }
    cout << "\n";
  }
}
