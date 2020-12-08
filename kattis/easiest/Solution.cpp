#include <iostream>

using namespace std;

int sumofdigits(int n) {
  int res = 0;
  while (n > 0) {
    res += n % 10;
    n = n / 10;
  }
  return res;
}

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    int e = sumofdigits(n);
    int p = 11;
    while (true) {
      if (sumofdigits(n * p) == e) {
        cout << p << endl;
        break;
      }
      p++;
    }
  }
  return 0;
}