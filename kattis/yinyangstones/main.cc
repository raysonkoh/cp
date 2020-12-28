#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  char c;
  int cCt = 0;
  int bCt = 0;
  while (cin >> c) {
    if (c == 'B') {
      cCt++;
    } else {
      // 'W'
      bCt++;
    }
  }
  cout << (cCt == bCt) << endl;
}