#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  string res = "";
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    int ascii = (int)c;
    if (ascii >= 65 && ascii <= 90) {
      res.push_back(c);
    }
  }
  cout << res << endl;
  return 0;
}