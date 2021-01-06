#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }
    cout << (s.find("problem") != s.npos ? "yes" : "no") << "\n";
  }
}