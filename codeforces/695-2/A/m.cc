#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 9 << '\n';
      continue;
    }

    cout << 98;
    int curr = 9;
    for (int i = 2; i < n; i++) {
      cout << curr;
      curr = (curr + 1) % 10;
    }

    cout << "\n";
  }
}