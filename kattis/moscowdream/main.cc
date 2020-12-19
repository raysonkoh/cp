#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  if (a >= 1 && b >= 1 && c >= 1 && a + b + c >= n && n >= 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}