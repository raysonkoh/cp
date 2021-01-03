#include <iostream>
#include <vector>

using namespace std;

pair<string, int> getNextWord(string s, int st) {
  string res = "";
  for (int i = st; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ' ') {
      return make_pair(res, i);
    }
    res.push_back(c);
  }
  return make_pair(res, s.length());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    pair<string, int> p = getNextWord(s, 0);
    int tolSum = stoi(p.first);
    vector<int> v;
    v.push_back(stoi(p.first));
    while (p.second < s.length()) {
      p = getNextWord(s, p.second + 1);
      tolSum += stoi(p.first);
      v.push_back(stoi(p.first));
    }

    for (int i = 0; i < v.size(); i++) {
      if (tolSum - v[i] == v[i]) {
        cout << v[i] << "\n";
        break;
      }
    }
  }
}