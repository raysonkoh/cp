#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool isvalid(vector<vector<int>> &m, pair<int, int> &p) {
  int curri = p.first;
  int currj = p.second;
  // check left
  for (int j = 0; j < currj; j++) {
    if (m[curri][j] == 1) {
      return false;
    }
  }

  // check right
  for (int j = 7; j > currj; j--) {
    if (m[curri][j] == 1) {
      return false;
    }
  }

  // check up
  for (int i = 0; i < curri; i++) {
    if (m[i][currj] == 1) {
      return false;
    }
  }

  // check down
  for (int i = 7; i > curri; i--) {
    if (m[i][currj] == 1) {
      return false;
    }
  }

  int tmpi;
  int tmpj;

  // check up left
  tmpi = curri - 1;
  tmpj = currj - 1;
  while (tmpi >= 0 && tmpj >= 0) {
    if (m[tmpi][tmpj] == 1) {
      return false;
    }
    tmpi--;
    tmpj--;
  }

  // check up right
  tmpi = curri - 1;
  tmpj = currj + 1;
  while (tmpi >= 0 && tmpj < 8) {
    if (m[tmpi][tmpj] == 1) {
      return false;
    }
    tmpi--;
    tmpj++;
  }

  // check down left
  tmpi = curri + 1;
  tmpj = currj - 1;
  while (tmpi < 8 && tmpj >= 0) {
    if (m[tmpi][tmpj] == 1) {
      return false;
    }
    tmpi++;
    tmpj--;
  }

  // check down right
  tmpi = curri + 1;
  tmpj = currj + 1;
  while (tmpi < 8 && tmpj < 8) {
    if (m[tmpi][tmpj] == 1) {
      return false;
    }
    tmpi++;
    tmpj++;
  }

  return true;
}

int main() {
  vector<vector<int>> m;
  map<int, pair<int, int>> queens;

  int numQueen = 0;
  string s;
  for (int i = 0; i < 8; i++) {
    vector<int> tmp;
    getline(cin, s);
    for (int j = 0; j < 8; j++) {
      char c = s.at(j);
      int val;
      if (c == '*') {
        queens[numQueen] = make_pair(i, j);
        numQueen++;
        val = 1;
      } else {
        val = 0;
      }
      tmp.push_back(val);
    }
    m.push_back(tmp);
  }

  // cout << "numQUeens: " << numQueen << endl;
  if (numQueen != 8) {
    cout << "invalid" << endl;
    return 0;
  }

  for (int i = 0; i < 8; i++) {
    pair<int, int> p = queens[i];
    if (!isvalid(m, p)) {
      cout << "invalid" << endl;
      return 0;
    }
  }

  cout << "valid" << endl;

  return 0;
}
