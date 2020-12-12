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

vector<vector<char>> leftrotate(vector<vector<char>> &m, int sides) {
  vector<vector<char>> rotate;
  for (int i = sides - 1; i >= 0; i--) {
    vector<char> tmp;
    for (int j = 0; j < sides; j++) {
      tmp.push_back(m[j][i]);
    }
    rotate.push_back(tmp);
  }
  return rotate;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int sides = 1;
    while (sides * sides < s.length()) {
      sides++;
    }

    while (s.length() < sides * sides) {
      s.push_back('*');
    }

    vector<vector<char>> m;
    for (int j = 0; j < sides; j++) {
      vector<char> tmp;
      for (int k = 0; k < sides; k++) {
        tmp.push_back(s.at(j * sides + k));
      }
      m.push_back(tmp);
    }

    // 3 x leftrotate
    // print(m, sides);
    vector<vector<char>> rotate = leftrotate(m, sides);
    // cout << endl;
    // print(rotate, sides);
    rotate = leftrotate(rotate, sides);
    // cout << endl;
    // print(rotate, sides);
    rotate = leftrotate(rotate, sides);
    // cout << endl;
    // print(rotate, sides);

    string res = "";
    for (int j = 0; j < sides; j++) {
      for (int k = 0; k < sides; k++) {
        if (rotate[j][k] != '*') {
          res.push_back(rotate[j][k]);
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
