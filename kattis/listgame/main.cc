#include <cmath>
#include <iostream>

using namespace std;

int main() {
  long x;
  cin >> x;
  long currtest = 2;
  int res = 0;
  while (x > 1 && x >= currtest * currtest) {
    while (x % currtest == 0) {
      x = x / currtest;
      res++;
    }
    currtest++;
  }
  if (x > 1) {
    res++;
  }
  cout << res << endl;
}