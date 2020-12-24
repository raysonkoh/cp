#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, p, q;
  cin >> n >> p >> q;
  int d = (p + q + 1) % (2 * n);

  // cout << d << endl;
  if (d >= 1 && d <= n) {
    cout << "paul" << endl;
  } else {
    cout << "opponent" << endl;
  }
}