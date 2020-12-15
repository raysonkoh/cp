#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;
  if (x == 1) {
    cout << 0 << " " << 1 << endl;
  } else {
    pair<int, int> curr = make_pair(0, 1);
    pair<int, int> prev = make_pair(1, 0);
    while (x > 1) {
      pair<int, int> newcurr =
          make_pair(curr.first + prev.first, curr.second + prev.second);
      prev = curr;
      curr = newcurr;
      x--;
    }
    cout << curr.first << " " << curr.second << endl;
  }
}
