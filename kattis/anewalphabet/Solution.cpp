#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  vector<string> v;
  v.push_back("@");
  v.push_back("8");
  v.push_back("(");
  v.push_back("|)");
  v.push_back("3");
  v.push_back("#");
  v.push_back("6");
  v.push_back("[-]");
  v.push_back("|");
  v.push_back("_|");
  v.push_back("|<");
  v.push_back("1");
  v.push_back("[]\\/[]");

  v.push_back("[]\\[]");
  v.push_back("0");
  v.push_back("|D");
  v.push_back("(,)");
  v.push_back("|Z");
  v.push_back("$");
  v.push_back("']['");
  v.push_back("|_|");
  v.push_back("\\/");
  v.push_back("\\/\\/");
  v.push_back("}{");
  v.push_back("`/");
  v.push_back("2");

  string res = "";
  for (int i = 0; i < s.length(); i++) {
    int ascii = (int)s.at(i);
    if (ascii >= 65 && ascii <= 90) {
      ascii += 32;
    }
    if (ascii >= 97 && ascii <= 122) {
      res += (v[ascii - 97]);
    } else {
      res.push_back(s.at(i));
    }
  }
  cout << res << endl;
  return 0;
}