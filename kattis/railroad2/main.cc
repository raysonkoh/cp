#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x, y;
  cin >> x >> y;
  if (y % 2 == 0) {
    cout << "possible" << endl;
  } else {
    cout << "impossible" << endl;
  }
}