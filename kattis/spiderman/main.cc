#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
    }

    map<int, pair<int, string>> currSols; // (dist, maxDist, sol)
    for (int i = 0; i < m; i++) {
      if (i == 0) {
        currSols[v[i]] = make_pair(v[i], "U");
        continue;
      }

      map<int, pair<int, string>> tmp;
      for (auto it : currSols) {
        int dist = it.first;
        pair<int, string> p = it.second;

        if (dist - v[i] >= 0) {
          // go down
          pair<int, string> next =
              make_pair(max(p.first, dist - v[i]), p.second + "D");
          if (tmp.find(dist - v[i]) != tmp.end()) {
            tmp[dist - v[i]] =
                tmp[dist - v[i]].first < next.first ? tmp[dist - v[i]] : next;
          } else {
            tmp[dist - v[i]] = next;
          }
        }
        // go up
        pair<int, string> next =
            make_pair(max(p.first, dist + v[i]), p.second + "U");
        if (tmp.find(dist + v[i]) != tmp.end()) {
          tmp[dist + v[i]] =
              tmp[dist + v[i]].first < next.first ? tmp[dist + v[i]] : next;
        } else {
          tmp[dist + v[i]] = next;
        }
      }
      currSols = tmp;
    }

    bool foundSol = false;
    for (auto it : currSols) {
      if (it.first == 0) {
        cout << it.second.second << "\n";
        foundSol = true;
        break;
      }
    }

    if (!foundSol) {
      cout << "IMPOSSIBLE\n";
    }
  }
}