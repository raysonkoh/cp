#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  long long a;
  cin >> a;
  cout << fixed << setprecision(8) << sqrtl(a) * 4 << endl;
  return 0;
}