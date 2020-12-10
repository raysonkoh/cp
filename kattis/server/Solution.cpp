#include <iostream>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int tmp = t;
    if (tmp - x >= 0) {
      // cout << "x: " << x << endl;
      t -= x;
      res++;
    } else {
      break;
    }
  }
  cout << res << endl;
  return 0;
}