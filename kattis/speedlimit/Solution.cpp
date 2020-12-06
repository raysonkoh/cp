#include <iostream>

using namespace std;

int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == -1) {
      break;
    }

    int res = 0;
    int accumHr = 0;
    for (int i = 0; i < n; i++) {
      int s, t;
      cin >> s >> t;
      res += s * (t - accumHr);
      accumHr = t;
    }
    cout << res << " miles" << endl;
  }

  return 0;
}