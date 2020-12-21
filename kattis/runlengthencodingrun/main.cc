#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string cmd, s;
  cin >> cmd >> s;
  if (cmd == "E") {
    int indx = 0;
    while (indx < s.length()) {
      char curr = s.at(indx);
      int count = 1;
      while (indx < s.length() - 1 && curr == s.at(indx + 1)) {
        count++;
        indx++;
      }
      cout << curr << count;
      indx++;
    }
    cout << endl;
  } else {
    // decode
    for (int i = 0; i < s.length(); i += 2) {
      char c = s.at(i);
      int count = s.at(i + 1) - '0';
      for (int j = 0; j < count; j++) {
        cout << c;
      }
    }
    cout << endl;
  }
}