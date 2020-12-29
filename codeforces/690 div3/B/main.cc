#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s == "2020") {
      // cout << "shortcircuit" << endl;
      cout << "YES\n";
      continue;
    }

    bool isFound = false;
    for (int i = 0; i < 5; i++) {
      int j = n - 5 + i;
      string tmp = s.substr(0, i) + s.substr(j + 1, n - j);
      // cout << "i: " << i << " j: " << j << " tmp: " << tmp << endl;
      if (tmp == "2020") {
        isFound = true;
        cout << "YES\n";
        break;
      }
    }
    if (!isFound) {
      cout << "NO\n";
    }
  }
}