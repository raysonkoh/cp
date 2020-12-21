#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int p, q, s;
  cin >> p >> q >> s;
  for (int i = 1; i <= s; i++) {
    if (i % p == 0 && i % q == 0) {
      cout << "yes" << endl;
      return 0;
    }
  }
  cout << "no" << endl;
}