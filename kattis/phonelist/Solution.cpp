#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<string> v;
    bool isConsistent = true;
    for (int j = 0; j < n; j++) {
      string s;
      cin >> s;
      v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (int j = 1; j < v.size(); j++) {
      string prev = v.at(j - 1);
      string curr = v.at(j);
      if (prev.length() > curr.length()) {
        continue;
      } else if (prev == curr.substr(0, prev.length())) {
        isConsistent = false;
      }
    }
    if (isConsistent) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}