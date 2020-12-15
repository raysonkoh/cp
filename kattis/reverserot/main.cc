#include <iostream>
#include <vector>

using namespace std;

int getindx(char c) {
  int ascii = (int)c;
  if (ascii >= 65 && ascii <= 90) {
    return ascii - 65;
  } else if (ascii == 95) {
    return 26;
  } else {
    return 27;
  }
}

string reverse(string s) {
  string res = "";
  for (int i = s.length() - 1; i >= 0; i--) {
    char c = s.at(i);
    res.push_back(c);
  }
  return res;
}

int main() {
  vector<char> v;
  for (int i = 0; i < 26; i++) {
    char c = (char)(i + 65);
    v.push_back(c);
  }
  v.push_back('_');
  v.push_back('.');

  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    string s;
    cin >> s;
    string rev = reverse(s);
    for (int i = 0; i < rev.length(); i++) {
      char c = rev.at(i);
      int currindx = getindx(c);
      int nextindx = (currindx + n) % 28;
      rev[i] = v[nextindx];
    }
    cout << rev << endl;
  }
}
