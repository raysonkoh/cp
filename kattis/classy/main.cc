#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<pair<string, string>> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << ", " << v[i].second << " | ";
  }
  cout << endl;
}

string convert(string s) {
  string res = "";
  string curr = "";
  for (int i = 0; i < s.length(); i++) {
    if (s.at(i) == '-') {
      if (curr == "upper") {
        res.push_back('2');
      } else if (curr == "middle") {
        res.push_back('1');
      } else {
        res.push_back('0');
      }
      curr = "";
    } else {
      curr.push_back(s.at(i));
    }
  }
  if (curr == "upper") {
    res.push_back('2');
  } else if (curr == "middle") {
    res.push_back('1');
  } else {
    res.push_back('0');
  }
  reverse(res.begin(), res.end());
  while (res.length() != 32) {
    res.push_back('0');
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<pair<string, string>> v;
    for (int j = 0; j < n; j++) {
      string name, title, tmp;
      cin >> name >> title >> tmp;
      name = name.substr(0, name.length() - 1);
      v.push_back(make_pair(convert(title), name));
    }
    sort(v.rbegin(), v.rend());
    for (int j = 0; j < n; j++) {
      cout << v[j].second << endl;
    }
    cout << "==============================" << endl;
  }
}