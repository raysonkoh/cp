#include <iostream>

using namespace std;

bool isPossible(int a, int b, int c) {
  return ((a + b == c) || (a - b == c) || (a * b == c) || (a == c * b));
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (isPossible(a, b, c) || isPossible(b, a, c)) {
      cout << "Possible" << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
  return 0;
}