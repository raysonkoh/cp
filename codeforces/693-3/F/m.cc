#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    map<int, int> colMap; // (col -> row) If both rows occupied, row = 3
    for (int i = 0; i < m; i++) {
      int r, c;
      cin >> r >> c;
      if (colMap.count(c) > 0) {
        colMap[c] = 3;
      } else {
        colMap[c] = r;
      }
    }

    int topOffset = 0;
    int prevCol = -1;
    bool foundSol = false;
    for (auto [col, row] : colMap) {
      int dist = col - prevCol + 1;

      if (topOffset != 0 && row == 3) {
        cout << "NO\n";
        foundSol = true;
        break;
      } else if (dist % 2 == 1) {
        if ((topOffset == 1 && row == 2) || (topOffset == -1 && row == 1)) {
          cout << "NO\n";
          foundSol = true;
          break;
        }
      } else if ((topOffset == 1 && row == 1) || (topOffset == -1 && row == 2)) {
        cout << "NO\n";
        foundSol = true;
        break;
      }

      if (row == 1) {
        topOffset--;
      } else if (row == 2) {
        topOffset++;
      }

      prevCol = col;
      topOffset %= 2;
    }

    if (!foundSol) {
      if (topOffset % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}