#include <iostream>
#include <map>

using namespace std;

int main() {
  string s;
  map<string, string> m;
  bool getQuery = false;
  while (getline(cin, s)) {
    if (s == "") {
      getQuery = true;
      continue;
    } else if (getQuery) {
      if (m.find(s) == m.end()) {
        cout << "eh" << endl;
      } else {
        cout << m.find(s)->second << endl;
      }
    } else {
      string first = "";
      string second = "";
      bool addFirst = true;
      for (int i = 0; i < s.length(); i++) {
        char c = s.at(i);
        if (c == ' ') {
          addFirst = false;
          continue;
        }
        if (addFirst) {
          first.push_back(c);
        } else {
          second.push_back(c);
        }
        m[second] = first;
      }
    }
  };

  return 0;
}