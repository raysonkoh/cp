#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    string res = "";
    char prevChar = '%';
    for (int j = 0; j < s.length(); j++) {
      char c = s.at(j);
      int ascii = (int)c;
      char add;
      int numToAdd;

      if (c == ' ') {
        add = '0';
        numToAdd = 1;
      } else if (ascii >= 97 && ascii <= 99) {
        // abc
        add = '2';
        numToAdd = ascii - 96;
      } else if (ascii >= 100 && ascii <= 102) {
        // def
        add = '3';
        numToAdd = ascii - 99;
      } else if (ascii >= 103 && ascii <= 105) {
        // ghi
        add = '4';
        numToAdd = ascii - 102;
      } else if (ascii >= 106 && ascii <= 108) {
        // jkl
        add = '5';
        numToAdd = ascii - 105;
      } else if (ascii >= 109 && ascii <= 111) {
        // mno
        add = '6';
        numToAdd = ascii - 108;
      } else if (ascii >= 112 && ascii <= 115) {
        // pqrs
        add = '7';
        numToAdd = ascii - 111;
      } else if (ascii >= 116 && ascii <= 118) {
        // tuv
        add = '8';
        numToAdd = ascii - 115;
      } else if (ascii >= 119 && ascii <= 122) {
        // wxyz
        add = '9';
        numToAdd = ascii - 118;
      }

      if (prevChar == add) {
        res.push_back(' ');
      }
      for (int k = 0; k < numToAdd; k++) {
        res.push_back(add);
      }

      prevChar = add;
    }
    cout << "Case #" << i + 1 << ": " << res << endl;
  }
  return 0;
}
