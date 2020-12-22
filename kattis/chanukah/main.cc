#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    double c, n;
    cin >> c >> n;
    cout << c << " " << (int)((n / 2.0) * (n + 1.0) + n) << endl;
  }
}