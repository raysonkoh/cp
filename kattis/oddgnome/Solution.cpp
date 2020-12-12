#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int g;
    cin >> g;
    int prev = -2;
    for (int j = 0; j < g; j++) {
      int x;
      cin >> x;
      // cout << "x: " << x << endl;
      if (j == 0) {
        prev = x;
        continue;
      }

      if (x != prev + 1) {
        // cout << "g: " << g << " j: " << j << endl;
        // cout << "x: " << x << " prev: " << prev << endl;
        cout << j + 1 << endl;
      } else {
        prev = x;
      }
    }
  }
  return 0;
}
