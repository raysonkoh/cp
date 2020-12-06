#include <iostream>
#include <string>

using namespace std;

int main() {
  long long n;
  cin >> n;

  string s = "";
  while (n > 0) {
    if (n % 2 == 1) {
      s.push_back('1');
    } else {
      s.push_back('0');
    }
    n = n / 2;
  }

  long long res = 0;
  long long exponent = 1;
  for (int i = s.length() - 1; i >= 0; i--) {
    char c = s.at(i);
    if (c == '1') {
      res += exponent;
    }
    exponent = exponent * 2;
  }
  cout << res << endl;

  return 0;
}