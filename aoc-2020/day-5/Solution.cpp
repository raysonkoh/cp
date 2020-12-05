#include <iostream>
#include <map>

using namespace std;

int getVal(string s, char valid) {
  int res = 0;
  int exponent = 1;
  for (int i = s.length() - 1; i >= 0; i--) {
    char c = s.at(i);
    if (c == valid) {
      res += exponent;
    }
    exponent *= 2;
  }

  return res;
}

int main() {
  int n = 815;
  int maxNum = -1;
  int minNum = INT_MAX;

  map<int, int> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    string row = s.substr(0, 7);
    string col = s.substr(7, 10);

    int rowNum = getVal(row, 'B');
    int colNum = getVal(col, 'R');

    int res = rowNum * 8 + colNum;
    maxNum = max(maxNum, res);
    minNum = min(minNum, res);
    m[res] = 1;
  }

  for (int i = minNum; i <= maxNum; i++) {
    if (m.find(i) == m.end()) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}