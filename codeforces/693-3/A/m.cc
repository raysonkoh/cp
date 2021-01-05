#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int w, h, n;
    cin >> w >> h >> n;
    int tolNum = 1;

    while (w % 2 == 0) {
      tolNum *= 2;
      w /= 2;
    }

    while (h % 2 == 0) {
      tolNum *= 2;
      h /= 2;
    }

    cout << (tolNum >= n ? "YES" : "NO") << endl;
  }
}