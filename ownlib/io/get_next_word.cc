#include <iostream>

using namespace std;

pair<string, int> getNextWord(string s, int st) {
  string res = "";
  for (int i = st; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ' ') {
      return make_pair(res, i);
    }
    res.push_back(c);
  }
  return make_pair(res, s.length());
}
