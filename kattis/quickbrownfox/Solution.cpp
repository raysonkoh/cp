#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  set<char> s;
  vector<char> missing;
  int n;
  cin >> n;
  string str;
  getline(cin, str);
  for (int i = 0; i < n; i++) {
    getline(cin, str);
    for (int j = 0; j < str.length(); j++) {
      char c = str.at(j);
      s.insert(c);
    }

    for (int i = 65; i <= 90; i++) {
      char upper = (char)i;
      char lower = (char)(i + 32);
      if (s.find(lower) == s.end() && s.find(upper) == s.end()) {
        missing.push_back(lower);
      }
    }

    sort(missing.begin(), missing.end());
    if (missing.size() == 0) {
      cout << "pangram" << endl;
    } else {
      cout << "missing ";
      for (int i = 0; i < missing.size(); i++) {
        cout << missing[i];
      }
      cout << endl;
    }
    s.clear();
    missing.clear();
  }
  return 0;
}