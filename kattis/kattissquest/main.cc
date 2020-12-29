#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<int, priority_queue<int>> m;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      int e, g;
      cin >> e >> g;
      if (m.find(e) == m.end()) {
        priority_queue<int> pq;
        pq.push(g);
        m[e] = pq;
      } else {
        m[e].push(g);
      }
    } else {
      // query
      int x;
      cin >> x;
      long long res = 0;
      while (x > 0) {
        auto it = m.lower_bound(x);
        if (it->first == x) {
          res += it->second.top();
          it->second.pop();
          if (it->second.size() == 0) {
            m.erase(it);
          }
          break;
        } else if (it == m.begin()) {
          break;
        } else {
          it--;
          res += it->second.top();
          it->second.pop();
          x -= it->first;
          if (it->second.size() == 0) {
            m.erase(it);
          }
        }
      }
      cout << res << "\n";
    }
  }
}