#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int c, n;
  cin >> c >> n;

  int currcapc = 0;

  for (int i = 0; i < n; i++) {
    int left, enter, stay;
    cin >> left >> enter >> stay;
    if ((i == 0 && left > 0) ||
        (i == n - 1 && (enter > 0 || stay > 0 || currcapc - left != 0))) {
      cout << "impossible" << endl;
      return 0;
    }

    int newcapc = currcapc + enter - left;
    int excesscapc = c - newcapc;
    if (newcapc < 0 || (newcapc > c) || (excesscapc > 0 && stay > 0)) {
      cout << "impossible" << endl;
      return 0;
    }
    currcapc = newcapc;
  }
  cout << "possible" << endl;
}
