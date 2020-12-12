#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  cout << fixed << setprecision(6)
       << ((double)(r - c) * (r - c)) / ((double)(r * r)) * 100.0 << endl;
  return 0;
}
