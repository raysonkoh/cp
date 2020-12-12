#include <iostream>

using namespace std;

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  string s;
  getline(cin, s);
  string res = "";

  int indx = 0;
  int consideredIndx = -1;
  while (indx < s.length() - 2) {
    char c = s.at(indx);
    char next = s.at(indx + 1);
    char nextNext = s.at(indx + 2);
    if (isVowel(c) && next == 'p' && isVowel(nextNext) && c == nextNext) {
      consideredIndx = indx + 2;
      indx += 3;
    } else {
      consideredIndx = indx;
      indx++;
    }
    res.push_back(c);
  }

  for (int i = consideredIndx + 1; i < s.length(); i++) {
    char c = s.at(indx);
    res.push_back(c);
  }

  cout << res << endl;

  return 0;
}
