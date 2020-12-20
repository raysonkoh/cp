#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  vector<string> v;
  vector<string> res;
  set<string> seen;
  while (cin >> s) {
    v.push_back(s);
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      string s1 = v[i];
      string s2 = v[j];
      string c1 = s1 + s2;
      string c2 = s2 + s1;
      if (seen.find(c1) == seen.end()) {
        res.push_back(c1);
        seen.insert(c1);
      }
      if (seen.find(c2) == seen.end()) {
        res.push_back(c2);
        seen.insert(c2);
      }
    }
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
}