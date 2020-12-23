#include <iostream>
#include <vector>

using namespace std;

bool validatePos(pair<int, int> &p, vector<vector<char>> &v) {
  int i = p.first;
  int j = p.second;
  // up then left
  if (i - 2 >= 0 && j - 1 >= 0 && v[i - 2][j - 1] == 'k') {
    return false;
  }
  // up then right
  if (i - 2 >= 0 && j + 1 < v[0].size() && v[i - 2][j + 1] == 'k') {
    return false;
  }
  // down then left
  if (i + 2 < v.size() && j - 1 >= 0 && v[i + 2][j - 1] == 'k') {
    return false;
  }
  // down then right
  if (i + 2 < v.size() && j + 1 < v[0].size() && v[i + 2][j + 1] == 'k') {
    return false;
  }
  // left then up
  if (i - 1 >= 0 && j - 2 >= 0 && v[i - 1][j - 2] == 'k') {
    return false;
  }
  // left then down
  if (i + 1 < v.size() && j - 2 >= 0 && v[i + 1][j - 2] == 'k') {
    return false;
  }
  // right then up
  if (i - 1 >= 0 && j + 2 < v[0].size() && v[i - 1][j + 2] == 'k') {
    return false;
  }
  // right then down
  if (i + 1 < v.size() && j + 2 < v[0].size() && v[i + 1][j + 2] == 'k') {
    return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<vector<char>> v(5, vector<char>(5));
  vector<pair<int, int>> kpos;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      char c;
      cin >> c;
      v[i][j] = c;
      if (c == 'k') {
        kpos.push_back(make_pair(i, j));
      }
    }
  }
  if (kpos.size() != 9) {
    cout << "invalid" << endl;
    return 0;
  }
  for (int i = 0; i < kpos.size(); i++) {
    if (!validatePos(kpos[i], v)) {
      cout << "invalid" << endl;
      return 0;
    }
  }
  cout << "valid" << endl;
}