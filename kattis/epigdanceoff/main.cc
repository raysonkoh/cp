#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> v(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      v[i][j] = c;
    }
  }
  int res = 0;
  for (int j = 0; j < m; j++) {
    bool foundNonEmpty = false;
    for (int i = 0; i < n; i++) {
      char c = v[i][j];
      if (c != '_') {
        foundNonEmpty = true;
        break;
      }
    }
    if (!foundNonEmpty) {
      res++;
    }
  }
  res++;
  cout << res << endl;
}