#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int c, n;
  while (cin >> c >> n) {
    vector<int> w(n, 0);
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> p[i] >> w[i];
    }

    vector<vector<int>> dp(n, vector<int>(c + 1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(c + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < c + 1; j++) {
        if (i == 0) {
          if (w[i] <= j) {
            dp[i][j] = p[i];
            parent[i][j] = make_pair(i, 0);
          } else {
            dp[i][j] = 0;
            parent[i][j] = make_pair(i, j);
          }
        } else {
          if (j - w[i] >= 0 && dp[i - 1][j - w[i]] + p[i] > dp[i - 1][j]) {
            dp[i][j] = dp[i - 1][j - w[i]] + p[i];
            parent[i][j] = make_pair(i - 1, j - w[i]);
          } else {
            dp[i][j] = dp[i - 1][j];
            parent[i][j] = make_pair(i - 1, j);
          }
        }
      }
    }

    vector<int> chosen;
    int row = n - 1;
    int col = c;
    while (true) {
      // cout << "row: " << row << " col: " << col << endl;
      pair<int, int> p = parent[row][col];
      if (col == p.second) {
        // did not choose item at row
      } else {
        chosen.push_back(row);
      }

      if (p.first == row && p.second == col) {
        break;
      } else {
        row = p.first;
        col = p.second;
      }
    }

    // cout << "cost: " << dp[n - 1][c] << endl;
    cout << chosen.size() << endl;
    if (chosen.size() > 0) {
      for (int i = 0; i < chosen.size(); i++) {
        cout << chosen[i] << " ";
      }
      cout << endl;
    }
  }
}