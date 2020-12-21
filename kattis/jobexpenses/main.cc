#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < 0) {
      res += -1 * x;
    }
  }
  cout << res << endl;
}