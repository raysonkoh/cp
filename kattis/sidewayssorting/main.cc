#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<pair<string, string>> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].second << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int r, c;
  bool isfirst = true;
  while (cin >> r >> c) {
    if (r == 0 && c == 0) {
      break;
    }

    if (isfirst) {
      isfirst = false;
    } else {
      cout << endl;
    }
    vector<pair<string, string>> v(c, make_pair("", ""));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        char ch;
        cin >> ch;
        v[j].first.push_back(tolower(ch));
        v[j].second.push_back(ch);
      }
    }
    sort(v.begin(), v.end());
    // print(v);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << v[j].second[i];
      }
      cout << endl;
    }
  }
}