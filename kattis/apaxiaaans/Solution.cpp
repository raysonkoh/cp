#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  string res = "";
  for (int i = 0; i < s.length(); i++) {
    if (i > 0 && s.at(i) == s.at(i - 1)) {
      continue;
    }
    res.push_back(s.at(i));
  }
  cout << res << endl;
  return 0;
}