#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int w, h;
  cin >> w >> h;
  int diag = sqrt(w * w + h * h);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x <= diag) {
      cout << "DA" << endl;
    } else {
      cout << "NE" << endl;
    }
  }
  return 0;
}