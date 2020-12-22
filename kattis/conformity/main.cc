#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<tuple<int, int, int, int, int>, int> m;
  vector<tuple<int, int, int, int, int>> tuples;
  int maxcount = 0;
  for (int i = 0; i < n; i++) {
    vector<int> v(5);
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      v[j] = x;
    }
    sort(v.begin(), v.end());
    tuple<int, int, int, int, int> t = make_tuple(v[0], v[1], v[2], v[3], v[4]);

    if (m.find(t) == m.end()) {
      tuples.push_back(t);
      m[t] = 1;
    } else {
      m[t]++;
    }
    maxcount = max(maxcount, m[t]);
  }
  int res = 0;
  for (int i = 0; i < tuples.size(); i++) {
    if (m[tuples[i]] == maxcount) {
      res += maxcount;
    }
  }
  cout << res << endl;
}