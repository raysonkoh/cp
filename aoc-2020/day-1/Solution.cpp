#include <iostream>

using namespace std;

long calc(long x);
long firstCalc(int n);

int main() {
  long res = firstCalc(100);

  cout << res << endl;
  return 0;
}

long firstCalc(int n) {
  long res = 0;
  for (int i = 0; i < n; i++) {
    long tmp;
    cin >> tmp;
    tmp = calc(tmp);
    while (tmp > 0) {
      res += tmp;
      tmp = calc(tmp);
    }
  }
  return res;
}

long calc(long x) { return (x / 3) - 2; }