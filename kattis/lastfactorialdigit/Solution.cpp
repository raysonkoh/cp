#include <iostream>

using namespace std;

int lastdigit(int n) {
  if (n == 1) {
    return 1;
  }
  return (n * lastdigit(n - 1)) % 10;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int res = lastdigit(n);
    cout << res << endl;
  }
  return 0;
}