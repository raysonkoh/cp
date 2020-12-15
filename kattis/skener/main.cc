#include <iostream>
#include <vector>

using namespace std;

int main() {
  int r, c, zr, zc;
  cin >> r >> c >> zr >> zc;
  vector<vector<char>> res;

  for (int i = 0; i < r * zr; i++) {
    vector<char> tmp;
    res.push_back(tmp);
  }

  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < c; j++) {
      char ch = s.at(j);
      for (int k = zr * i; k < zr * (i + 1); k++) {
        for (int l = zc * j; l < zc * (j + 1); l++) {
          res[k].push_back(ch);
        }
      }
    }
  }

  for (int i = 0; i < res.size(); i++) {
    bool isfirst = true;
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j];
    }
    cout << endl;
  }
}
