#include <iostream>

using namespace std;

bool sumtox(int i, int x) {
  string s = to_string(i);
  int res = 0;
  for (int i = 0; i < s.length(); i++) {
    int num = s.at(i) - '0';
    res += num;
  }
  return res == x;
}

int main() {
  int l, d, x;
  cin >> l >> d >> x;
  for (int i = l; i <= d; i++) {
    if (sumtox(i, x)) {
      cout << i << endl;
      break;
    }
  }

  for (int i = d; i >= l; i--) {
    if (sumtox(i, x)) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}