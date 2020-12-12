#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {
  priority_queue<pair<int, int>> sofar;
  map<int, vector<int>> m;
  int maxT = 0;
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    int ci, ti;
    cin >> ci >> ti;
    if (m.find(ti) == m.end()) {
      vector<int> tmp;
      m[ti] = tmp;
    }
    m[ti].push_back(ci);
    maxT = max(maxT, ti);
  }

  long long res = 0;
  for (int time = maxT; time >= 0; time--) {
    if (m.find(time) != m.end()) {
      vector<int> tmp = m[time];
      for (int j = 0; j < tmp.size(); j++) {
        sofar.push(make_pair(tmp[j], time));
      }
    }

    if (sofar.size() > 0) {
      pair<int, int> p = sofar.top();
      sofar.pop();
      res += p.first;
    }
  }

  cout << res << endl;
  return 0;
}
