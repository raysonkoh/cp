#include <iostream>
#include <map>

using namespace std;

pair<string, int> getNextNum(string s, int start) {
  string res = "";
  for (int i = start; i < s.length(); i++) {
    if (s.at(i) == ' ') {
      return make_pair(res, i);
    } else {
      res.push_back(s.at(i));
    }
  }
  return make_pair(res, s.length() - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int k;
  cin >> k;
  map<int, int> parent;
  string line;
  getline(cin, line);
  while (getline(cin, line)) {
    if (line == "-1") {
      break;
    }
    int indx = 0;
    int par = -1;
    while (indx < line.length()) {
      pair<string, int> p = getNextNum(line, indx);
      indx = p.second + 1;
      if (par == -1) {
        par = stoi(p.first);
      } else {
        parent[stoi(p.first)] = par;
      }
    }
  }
  int curr = k;
  while (parent.find(curr) != parent.end()) {
    cout << curr << " ";
    curr = parent.find(curr)->second;
  }
  cout << curr << "\n";
}