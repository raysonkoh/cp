#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x;
  cin >> x;
  if (x <= 2) {
    cout << 1 << endl;
  } else {
    cout << x - 2 << endl;
  }
}