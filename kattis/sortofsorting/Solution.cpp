#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  bool firstLine = true;
  while (cin >> n) {
    if (n == 0) {
      break;
    } else if (firstLine) {
      firstLine = false;
    } else {
      cout << endl;
    }

    map<string, queue<string>> m;
    vector<string> v;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if (m.find(s.substr(0, 2)) == m.end()) {
        queue<string> tmp;
        tmp.push(s);
        m[s.substr(0, 2)] = tmp;
      } else {
        m[s.substr(0, 2)].push(s);
      }
      v.push_back(s.substr(0, 2));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      cout << m.find(v[i])->second.front() << endl;
      m.find(v[i])->second.pop();
    }
  }

  return 0;
}