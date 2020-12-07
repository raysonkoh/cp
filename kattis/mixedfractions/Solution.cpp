#include <iostream>

using namespace std;

int main() {
  long n, d;
  while (cin >> n >> d) {
    if (n == 0 && d == 0) {
      break;
    }
    long quot = n / d;
    long remain = n - quot * d;
    cout << quot << " " << remain << " / " << d << endl;
  }
  return 0;
}