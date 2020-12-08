#include <iostream>
#include <set>

using namespace std;

int main() {
  set<string> s;
  string str;
  while (cin >> str) {
    if (s.find(str) != s.end()) {
      cout << "no" << endl;
      return 0;
    } else {
      s.insert(str);
    }
  }
  cout << "yes" << endl;
  return 0;
}