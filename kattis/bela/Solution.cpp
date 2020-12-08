#include <iostream>

using namespace std;

int getval(char d, bool isDom) {
    if (d == 'A') {
        return 11;
    } else if (d == 'K') {
        return 4;
    } else if (d == 'Q') {
        return 3;
    } else if (d == 'J') {
        if (isDom) {
            return 20;
        }
        return 2;
    } else if ( d == 'T') {
        return 10;
    } else if (d == '9') {
        if (isDom) {
            return 14;
        }
        return 0;
    } else if (d == '8' ) {
        return 0;
    } else if (d == '7'){ 
        return 0;
    }
    return 0;
}

int main() {
  int n;
  char b;
  cin >> n >> b;
  int res = 0;
  for (int i = 0; i < 4 * n; i++) {
    char d, s;
    cin >> d >> s;
    if (s == b) {
      res += getval(d, true);
    } else {
      res += getval(d,false);
    }
  }
  cout << res << endl;
  return 0;
}