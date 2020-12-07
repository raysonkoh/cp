#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  double c;
  int l;
  cin >> c >> l;
  double tolArea = 0.0;
  for (int i = 0; i < l; i++) {
    double w, len;
    cin >> w >> len;
    tolArea += w * len;
  }
  double res = tolArea * c;
  cout << setprecision(8) << fixed << res << endl;

  return 0;
}