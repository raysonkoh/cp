#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i;
  while (cin >> i) {
    if (i == 1) {
      cout << 1 << '\n';
    } else {
      cout << 2 * i - 2 << '\n';
    }
  }
}