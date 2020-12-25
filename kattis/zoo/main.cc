#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string getAnimal(string s) {
  string res = "";
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == ' ') {
      return res;
    }
    res.insert(res.begin(), tolower(s[i]));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  int caseNum = 1;
  while (getline(cin, s)) {
    int n = stoi(s);
    if (n == 0) {
      break;
    }
    map<string, int> m;
    vector<string> v;
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      string animal = getAnimal(s);
      if (m.find(animal) == m.end()) {
        v.push_back(animal);
        m[animal] = 0;
      }
      m[animal]++;
    }
    sort(v.begin(), v.end());
    cout << "List " << caseNum << ":" << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " | " << m[v[i]] << endl;
    }
    caseNum++;
  }
}