#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  string s;
  getline(cin, s);
  for (int i = 0; i < t; i++) {
    getline(cin, s);
    if (s.length() >= 11 && s.substr(0, 10) == "simon says") {
      cout << s.substr(11, s.length() - 11) << endl;
    } else {
      cout << endl;
    }
  }
}