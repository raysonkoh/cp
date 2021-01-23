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
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double sx, sy, dx, dy;
  cin >> sx >> sy >> dx >> dy;
  int n;
  cin >> n;
  vector<pair<double, double>> loc(n + 2);
  loc[0] = {sx, sy};
  loc[loc.size() - 1] = {dx, dy};
  for (int i = 1; i <= n; i++) {
    double x, y;
    cin >> x >> y;
    loc[i] = {x, y};
  }

  vector<vector<double>> distance(n + 2, vector<double>(n + 2));
  for (int i = 0; i < distance.size(); i++) {
    for (int j = 0; j < distance.size(); j++) {
      if (i == j)
        distance[i][j] = 0;
      else {
        double distBet = sqrt(pow(abs(loc[i].first - loc[j].first), 2) + pow(abs(loc[i].second - loc[j].second), 2));
        if (i == 0 || i == n + 1) {
          double time = distBet / 5.0;
          distance[i][j] = time;
        } else {
          double time = distBet / 5.0;
          double jump = abs(distBet - 50.0);
          time = min(time, (jump / 5.0) + 2.0);
          distance[i][j] = time;
        }
      }
    }
  }

  /*
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < n + 2; j++) {
      cout << distance[i][j] << ' ';
    }
    cout << endl;
  }
  */

  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
  vector<double> dist(n + 2, 1e18);
  dist[0] = 0;
  pq.push({dist[0], 0});

  while (pq.size() > 0) {
    auto [d, nd] = pq.top();
    pq.pop();

    if (dist[nd] < d) {
      continue;
    }

    for (int i = 0; i < distance.size(); i++) {
      if (i == nd)
        continue;
      if (d + distance[nd][i] < dist[i]) {
        dist[i] = d + distance[nd][i];
        pq.push({dist[i], i});
      }
    }
  }

  cout << fixed << setprecision(5) << dist[n + 1] << '\n';
}
