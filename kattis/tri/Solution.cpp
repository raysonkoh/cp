#include <iostream>

using namespace std;

int main() {
  int a1, a2, a3;
  char s1, s2;
  cin >> a1 >> a2 >> a3;
  if (a1 * a2 == a3) {
    s1 = '*';
    s2 = '=';
  } else if (a1 + a2 == a3) {
    s1 = '+';
    s2 = '=';
  } else if (a1 - a2 == a3) {
    s1 = '-';
    s2 = '=';
  } else if (a1 / a2 == a3) {
    s1 = '/';
    s2 = '=';
  } else if (a1 == a2 * a3) {
    s1 = '=';
    s2 = '*';
  } else if (a1 == a2 + a3) {
    s1 = '=';
    s2 = '+';
  } else if (a1 == a2 - a3) {
    s1 = '=';
    s2 = '-';
  } else {
    s1 = '=';
    s2 = '/';
  }

  cout << a1 << s1 << a2 << s2 << a3 << endl;

  return 0;
}