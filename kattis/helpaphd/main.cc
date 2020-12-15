#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "P=NP") {
      cout << "skipped" << endl;
      continue;
    }

    string a = "";
    string b = "";
    bool isfirst = true;
    for (int j = 0; j < s.length(); j++) {
      char c = s.at(j);
      if (c == '+') {
        isfirst = false;
        continue;
      }
      if (isfirst) {
        a.push_back(c);
      } else {
        b.push_back(c);
      }
    }
    cout << stoi(a) + stoi(b) << endl;
  }
}
