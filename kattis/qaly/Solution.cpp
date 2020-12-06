#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  double res = 0;
  for (int i = 0; i < n; i++) {
    double q, y;
    cin >> q >> y;
    res += q * y;
  }
  cout << res << endl;
  return 0;
}