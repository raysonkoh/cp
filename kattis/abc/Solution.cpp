#include <iostream>

using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int a, b, c;
  a = min(min(x, y), z);
  c = max(max(x, y), z);

  if (x != a && x != c) {
    b = x;
  } else if (y != a && y != c) {
    b = y;
  } else if (z != a && z != c) {
    b = z;
  }

  string s;
  cin >> s;
  for (int i = 0; i < 3; i++) {
    char ch = s.at(i);
    if (ch == 'A') {
      cout << a;
    } else if (ch == 'B') {
      cout << b;
    } else {
      cout << c;
    }
    if (i < 2) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}