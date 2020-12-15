#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int res = max(b - a - 1, c - b - 1);
  cout << res << endl;
}