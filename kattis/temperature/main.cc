#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x, y;
  cin >> x >> y;

  if (x == 0 && y == 1) {
    cout << "ALL GOOD" << endl;
  } else {
    int divideby = 1 - y;
    if (divideby == 0) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << fixed << setprecision(8) << ((double)x) / ((double)divideby)
           << endl;
    }
  }
}