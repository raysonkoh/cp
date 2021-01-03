#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int r, c;
  cin >> r >> c;
  vector<vector<char>> v(r, vector<char>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }
  int num0 = 0;
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  int num4 = 0;
  for (int i = 0; i < r - 1; i++) {
    for (int j = 0; j < c - 1; j++) {
      char a = v[i][j];
      char b = v[i][j + 1];
      char c = v[i + 1][j];
      char d = v[i + 1][j + 1];
      if (a == '#' || b == '#' || c == '#' || d == '#') {
        continue;
      }
      int tmp = (a == 'X') + (b == 'X') + (c == 'X') + (d == 'X');
      switch (tmp) {
      case 0:
        num0++;
        break;
      case 1:
        num1++;
        break;
      case 2:
        num2++;
        break;
      case 3:
        num3++;
        break;
      case 4:
        num4++;
        break;
      }
    }
  }
  cout << num0 << "\n";
  cout << num1 << "\n";
  cout << num2 << "\n";
  cout << num3 << "\n";
  cout << num4 << "\n";
}