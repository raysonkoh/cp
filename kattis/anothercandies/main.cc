#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    __uint128_t s = 0;
    for (int j = 0; j < n; j++) {
      long long x;
      cin >> x;
      s += x;
    }
    if (s % n == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}