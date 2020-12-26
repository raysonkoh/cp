#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    string txt;
    getline(cin, txt);
    long long offset = 0;
    bool isFirst = true;
    while (txt.find(s) != txt.npos) {
      long long indx = txt.find(s);
      txt.erase(indx, s.length());
      if (isFirst) {
        isFirst = false;
        cout << indx + offset;
      } else {
        cout << " " << indx + offset;
      }
      offset += s.length();
    }
    cout << endl;
  }
}