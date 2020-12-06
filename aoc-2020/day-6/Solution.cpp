#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int res = 0;
  string s;

  map<char, int> m;
  map<char, int> tmp;
  bool isFirstPerson = true;

  while (getline(cin, s)) {
    if (s == "") {
      res += m.size();
      m.clear();
      tmp.clear();
      isFirstPerson = true;
    } else {
      for (int i = 0; i < s.length(); i++) {
        char c = s.at(i);
        if (isFirstPerson) {
          m[c] = 1;
        } else if (m.find(c) != m.end()) {
          tmp[c] = 1;
        }
      }

      if (isFirstPerson) {
        isFirstPerson = false;
      } else {
        m = tmp;
        tmp.clear();
      }
    }
  }
  res += m.size();

  cout << res << endl;
  return 0;
}