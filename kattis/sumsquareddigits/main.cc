#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int dataNum, b, n;
    cin >> dataNum >> b >> n;
    int res = 0;
    while (n > 0) {
      int remain = n % b;
      res += remain * remain;
      n = n / b;
    }
    cout << dataNum << " " << res << endl;
  }
}