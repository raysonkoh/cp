#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  double exp = ((double)(n + 1 + m + 1)) / 2.0;
  if (n == m) {
    cout << exp << endl;
  } else {
    // force n > m
    if (n < m) {
      int tmp = n;
      n = m;
      m = tmp;
    }

    int tolEqual = n - m + 1;
    double offset = ((double)(tolEqual - 1)) / 2.0;
    for (double i = exp - offset; i <= exp + offset; i++) {
      cout << i << endl;
    }
  }

  return 0;
}