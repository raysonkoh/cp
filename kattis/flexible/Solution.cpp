#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int w, p;
  cin >> w >> p;
  vector<int> v;
  v.push_back(0);
  vector<int> res;
  set<int> s;
  for (int i = 0; i <= p; i++) {
    int l;
    if (i == p) {
      l = w;
    } else {
      cin >> l;
    }

    for (int j = 0; j < v.size(); j++) {
      int curr = v[j];
      int compute = l - v[j];
      if (s.find(compute) == s.end()) {
        s.insert(compute);
        res.push_back(compute);
      }
    }
    v.push_back(l);
  }

  sort(res.begin(), res.end());

  for (int i = 0; i < res.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i];
  }
  cout << endl;
  return 0;
}
