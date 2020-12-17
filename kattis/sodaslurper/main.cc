#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int e, f, c;
  cin >> e >> f >> c;
  int curr = e + f;
  int res = 0;
  while ((curr / c) > 0) {
    res += curr / c;
    curr = (curr / c) + (curr % c);
  }
  cout << res << endl;
}