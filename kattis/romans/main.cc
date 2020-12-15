#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double x;
  cin >> x;
  double res = x * 1000.0 * (5280.0 / 4854.0);
  int intres = res;
  if (res - intres >= 0.5) {
    cout << intres + 1 << endl;
  } else {
    cout << intres << endl;
  }
}