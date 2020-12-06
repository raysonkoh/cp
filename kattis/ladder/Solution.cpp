#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int h, v;
  cin >> h >> v;
  int res = (h / sin((double)v * M_PI / (double)180)) + 1;
  cout << res << endl;
  return 0;
}