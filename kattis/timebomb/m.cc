#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> v0 = {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}};
static vector<vector<int>> v1 = {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}};
static vector<vector<int>> v2 = {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}};
static vector<vector<int>> v3 = {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}};
static vector<vector<int>> v4 = {{1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1}};
static vector<vector<int>> v5 = {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}};
static vector<vector<int>> v6 = {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
static vector<vector<int>> v7 = {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}};
static vector<vector<int>> v8 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
static vector<vector<int>> v9 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}};

bool checkEq(vector<vector<int>> &v, vector<vector<int>> &t) {
  for (int i = 0; i < v.size(); i++)
    for (int j = 0; j < v[i].size(); j++)
      if (v[i][j] != t[i][j])
        return false;
  return true;
}

int parseDigit(vector<vector<int>> &v) {
  if (checkEq(v, v0)) {
    return 0;
  } else if (checkEq(v, v1)) {
    return 1;
  } else if (checkEq(v, v2)) {
    return 2;
  } else if (checkEq(v, v3)) {
    return 3;
  } else if (checkEq(v, v4)) {
    return 4;
  } else if (checkEq(v, v5)) {
    return 5;
  } else if (checkEq(v, v6)) {
    return 6;
  } else if (checkEq(v, v7)) {
    return 7;
  } else if (checkEq(v, v8)) {
    return 8;
  } else if (checkEq(v, v9)) {
    return 9;
  } else {
    return -1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> v;
  string s;
  while (getline(cin, s)) {
    vector<int> tmp;
    for (int i = 0; i < s.length(); i++) {
      tmp.push_back(s.at(i) == '*');
    }
    v.push_back(tmp);
  }
  vector<vector<int>> ph(5, vector<int>(3));
  int num = 0;
  int j = 0;
  while (j < v[0].size()) {
    int tmp = 0;
    int tmp2 = j + 3;
    for (; j < tmp2; j++, tmp++) {
      for (int i = 0; i < 5; i++) {
        ph[i][tmp] = v[i][j];
      }
    }
    int digit = parseDigit(ph);
    // cout << digit << endl;
    if (digit == -1) {
      cout << "BOOM!!\n";
      return 0;
    }
    num = num * 10 + digit;
    j++;
  }

  cout << (num % 6 == 0 ? "BEER!!" : "BOOM!!") << "\n";
}