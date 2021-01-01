#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  bool isFirst = true;

  while (cin >> n) {
    if (n == 0) {
      break;
    }

    /*
    if (isFirst) {
      isFirst = false;
    } else {
      cout << "\n";
    }
    */

    int p1 = 0; // use for TAKE
    int p2 = 0; // use for DROP

    while (n--) {
      string cmd;
      int m;
      cin >> cmd >> m;
      if (cmd == "DROP") {
        cout << "DROP 2 " << m << "\n";
        p2 += m;
      } else {
        // TAKE
        if (p1 >= m) {
          cout << "TAKE 1 " << m << "\n";
          p1 -= m;
          m = 0;
        } else {
          if (p1 > 0) {
            cout << "TAKE 1 " << p1 << "\n";
            m -= p1;
            p1 = 0;
          }
          cout << "MOVE 2->1 " << p2 << "\n";
          cout << "TAKE 1 " << m << "\n";
          p1 = p2 - m;
          p2 = 0;
        }
      }
    }
    cout << "\n";
  }
}