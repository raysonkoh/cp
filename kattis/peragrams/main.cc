#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  int count[26];
  for (int i = 0; i < 26; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < s.length(); i++) {
    int ascii = (int)s.at(i);
    int indx = ascii - 97;
    count[indx]++;
  }

  int numodd = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] % 2 == 1) {
      numodd++;
    }
  }
  if (numodd == 0) {
    cout << 0 << endl;
  } else {
    cout << numodd - 1 << endl;
  }
}