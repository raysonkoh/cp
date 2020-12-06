#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int res = 1;
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    if (res == 1) {
      if (c == 'A') {
        res = 2;
      } else if (c == 'C') {
        res = 3;
      }
    } else if (res == 2) {
      if (c == 'A') {
        res = 1;
      } else if (c == 'B') {
        res = 3;
      }
    } else {
      if (c == 'B') {
        res = 2;
      } else if (c == 'C') {
        res = 1;
      }
    }
  }
  cout << res << endl;
  return 0;
}