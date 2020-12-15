#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<char>> &m, int sides) {
  for (int i = 0; i < sides; i++) {
    for (int j = 0; j < sides; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

vector<vector<char>> right_rotate(vector<vector<char>> &m, int sides) {
  vector<vector<char>> res;
  for (int j = 0; j < sides; j++) {
    vector<char> tmp;
    for (int i = sides - 1; i >= 0; i--) {
      tmp.push_back(m[i][j]);
    }
    res.push_back(tmp);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int sides = sqrt(s.length());
    vector<vector<char>> m;
    for (int r = 0; r < sides; r++) {
      vector<char> tmp;
      for (int c = 0; c < sides; c++) {
        char ch = s.at(r * sides + c);
        tmp.push_back(ch);
      }
      m.push_back(tmp);
    }
    // print(m, sides);
    vector<vector<char>> rot = right_rotate(m, sides);
    rot = right_rotate(rot, sides);
    rot = right_rotate(rot, sides);
    // print(rot, sides);
    string res = "";
    for (int r = 0; r < sides; r++) {
      for (int c = 0; c < sides; c++) {
        char ch = rot[r][c];
        res.push_back(ch);
      }
    }
    cout << res << endl;
  }
}
