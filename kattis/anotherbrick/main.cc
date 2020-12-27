#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int h, w, n;
  cin >> h >> w >> n;
  int currH = 0;
  int currW = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    currW += x;
    if (currW > w) {
      cout << "NO" << endl;
      return 0;
    } else if (currW == w) {
      currW = 0;
      currH++;
      if (currH == h) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}