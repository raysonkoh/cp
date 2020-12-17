#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int prev, curr;
    int res = 0;
    bool setprev = false;
    while (cin >> curr) {
      if (curr == 0) {
        break;
      }

      if (!setprev) {
        prev = curr;
        setprev = true;
      } else {
        if (curr > 2 * prev) {
          res += curr - (2 * prev);
        }
        prev = curr;
      }
    }
    cout << res << endl;
  }
}