#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    double n;
    cin >> n;
    int res = ceil(n / 400.0);
    cout << res << endl;
  }
  return 0;
}
