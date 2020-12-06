#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long r, e, c;
    cin >> r >> e >> c;
    long prof = e - c;
    if (prof == r) {
      cout << "does not matter" << endl;
    } else if (prof > r) {
      cout << "advertise" << endl;
    } else {
      cout << "do not advertise" << endl;
    }
  }
  return 0;
}