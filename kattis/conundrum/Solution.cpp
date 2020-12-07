#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < s.length(); i += 3) {
    char cf = s.at(i);
    char cs = s.at(i + 1);
    char ct = s.at(i + 2);
    if (cf != 'P') {
      count++;
    }
    if (cs != 'E') {
      count++;
    }
    if (ct != 'R') {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}