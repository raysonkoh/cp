#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<pair<string, string>> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << "(" << v[i].first << ", " << v[i].second << ") ";
  }
  cout << endl;
}

string convert(string classStr) {
  string res = "";
  string curr = "";
  for (int i = 0; i < classStr.length(); i++) {
    char ch = classStr.at(i);
    if (ch == '-') {
      if (curr == "upper") {
        res.push_back('2');
      } else if (curr == "middle") {
        res.push_back('1');
      } else {
        // lower
        res.push_back('0');
      }
      curr = "";
    } else {
      curr.push_back(ch);
    }
  }
  if (curr == "upper") {
    res.push_back('2');
  } else if (curr == "middle") {
    res.push_back('1');
  } else {
    // lower
    res.push_back('0');
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    vector<pair<string, string>> v(n);
    int maxStrLen = 0;
    for (int i = 0; i < n; i++) {
      string s;
      getline(cin, s);
      string name = s.substr(0, s.find(":"));
      string rest = s.substr(s.find(":") + 2);
      rest = rest.substr(0, rest.length() - 6);
      v[i] = make_pair(convert(rest), name);
      maxStrLen = max(maxStrLen, (int)v[i].first.length());
      // cout << "name: " << name << endl;
      // cout << "classes: " << rest << endl;
      // cout << "convert: " << convert(rest) << endl;
    }
    for (int i = 0; i < n; i++) {
      while (v[i].first.length() < maxStrLen) {
        v[i].first.push_back('1');
      }
    }
    sort(v.begin(), v.end(),
         [](const pair<string, string> &p1, const pair<string, string> &p2) {
           if (p1.first == p2.first) {
             return p1.second < p2.second;
           }
           return p1.first > p2.first;
         });
    // print(v);
    for (int i = 0; i < n; i++) {
      cout << v[i].second << "\n";
    }
    cout << "==============================" << endl;
  }
}