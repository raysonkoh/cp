#include <iostream>

using namespace std;

int getRotateVal(string &s) {
  int res = 0;
  for (int i = 0; i < s.length(); i++) {
    int ascii = (int)s.at(i);
    ascii -= 65;
    res += ascii;
  }
  return res;
}

void rotate(string &s, int rotateVal) {
  for (int i = 0; i < s.length(); i++) {
    int ascii = (int)s.at(i);
    ascii -= 65;
    int newascii = (ascii + rotateVal) % 26;
    char c = (char)(newascii + 65);
    s[i] = c;
  }
}

void rotate(string &s1, string &s2) {
  for (int i = 0; i < s1.length(); i++) {
    int ascii = (int)s1.at(i);
    int s2ascii = (int)s2.at(i);
    ascii -= 65;
    s2ascii -= 65;
    ascii = (ascii + s2ascii) % 26;
    ascii += 65;
    char c = (char)ascii;
    s1[i] = c;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, s1, s2;
  getline(cin, s);
  s1 = s.substr(0, s.length() / 2);
  s2 = s.substr(s.length() / 2, s.length() / 2);
  rotate(s1, getRotateVal(s1));
  rotate(s2, getRotateVal(s2));
  // cout << s1 << endl;
  // cout << s2 << endl;
  rotate(s1, s2);
  cout << s1 << endl;
}