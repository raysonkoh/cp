#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int g;
    cin >> g;
    int res = 0;
    for (int j = 0; j < g; j++) {
      long c;
      cin >> c;
      res = res ^ c;
    }
    cout << "Case #" << (i + 1) << ": " << res << endl;
  }
  return 0;
}