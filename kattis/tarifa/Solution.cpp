#include <iostream>

using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  long res = 0;
  for (int i = 0; i < n; i++) {
    res += x;

    int tmp;
    cin >> tmp;

    res -= tmp;
  }
  res += x;
  cout << res << endl;
  return 0;
}