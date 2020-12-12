#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<double, queue<string>> m;
  vector<double> v;
  for (int i = 0; i < n; i++) {
    // cout << s << endl;
    string s1, s2;
    cin >> s1 >> s2;
    string color;
    double diam;
    if (((int)s1.at(0) >= 97) && ((int)s1.at(0) <= 122)) {
      // color radius
      diam = 2 * stoi(s2);
      color = s1;
    } else {
      // diameter color
      diam = stoi(s1);
      color = s2;
    }

    if (m.find(diam) == m.end()) {
      queue<string> tmp;
      m[diam] = tmp;
    }
    m[diam].push(color);
    v.push_back(diam);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    cout << m.find(v[i])->second.front() << endl;
    m.find(v[i])->second.pop();
  }
  return 0;
}
