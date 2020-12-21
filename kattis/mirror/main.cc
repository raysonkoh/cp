#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> m(r, vector<char>(c, 0));
    for (int row = 0; row < r; row++) {
      for (int col = 0; col < c; col++) {
        char ch;
        cin >> ch;
        m[row][col] = ch;
      }
    }

    vector<vector<char>> res(r, vector<char>(c, 0));
    for (int row = 0; row < r; row++) {
      for (int col = 0; col < c; col++) {
        res[r - 1 - row][c - 1 - col] = m[row][col];
      }
    }

    cout << "Test " << i + 1 << endl;
    for (int row = 0; row < r; row++) {
      for (int col = 0; col < c; col++) {
        cout << res[row][col];
      }
      cout << endl;
    }
  }
}