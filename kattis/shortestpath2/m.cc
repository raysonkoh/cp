#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

int closestTime(int curr, int t0, int p) {
  if (p == 0)
    return curr <= t0 ? t0 : -1;

  if (curr <= t0)
    return t0;

  int best = t0;
  while (curr > best) {
    best += p;
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, q, s;
  while (cin >> n >> m >> q >> s) {
    if (n == 0 && m == 0 && q == 0 && s == 0)
      break;
    vector<vector<tuple<int, int, int, int>>> adjList(n, vector<tuple<int, int, int, int>>());  // (nei, t0, P, d)
    for (int i = 0; i < m; i++) {
      int u, v, t0, p, d;
      cin >> u >> v >> t0 >> p >> d;
      adjList[u].push_back({v, t0, p, d});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, 1e9);
    dist[s] = 0;
    pq.push({dist[s], s});
    while (pq.size() > 0) {
      auto [d, nd] = pq.top();
      // cout << ">>>>>>>>>>>>>>>>> nd: " << nd << endl;
      pq.pop();
      if (d > dist[nd])
        continue;

      for (auto [nei, t0, p, wt] : adjList[nd]) {
        int tmp = closestTime(d, t0, p);
        // cout << "d: " << d << " t0: " << t0 << " p: " << p << endl;
        // cout << "nei: " << nei << " tmp: " << tmp << endl;
        if (tmp == -1)
          continue;
        if (tmp + wt < dist[nei]) {
          dist[nei] = tmp + wt;
          pq.push({dist[nei], nei});
        }
      }
    }

    while (q--) {
      int x;
      cin >> x;
      if (dist[x] == 1e9)
        cout << "Impossible\n";
      else
        cout << dist[x] << '\n';
    }
  }
}
