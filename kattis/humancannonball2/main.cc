#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    double v0, theta, x1, h1, h2;
    cin >> v0 >> theta >> x1 >> h1 >> h2;
    // cout << "v0: " << v0 << " theta: " << theta << " x1: " << x1
    //     << " h1: " << h1 << " h2: " << h2 << endl;
    theta = (M_PI / 180.0) * theta;
    double t = x1 / (v0 * cos(theta));
    double y = v0 * t * sin(theta) - (0.5) * 9.81 * t * t;
    // cout << "t: " << t << endl;
    // cout << "y: " << y << endl;
    if (y - h1 >= 1 && h2 - y >= 1) {
      cout << "Safe" << endl;
    } else {
      cout << "Not Safe" << endl;
    }
  }
}
