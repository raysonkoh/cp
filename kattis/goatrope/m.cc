#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  double xoff = max(x1 - x, x - x2);
  double yoff = max(y1 - y, y - y2);

  if (xoff <= 0) {
    cout << yoff << '\n';
  } else if (yoff <= 0) {
    cout << xoff << '\n';
  } else {
    cout << fixed << setprecision(8) << sqrt(xoff * xoff + yoff * yoff) << '\n';
  }
}