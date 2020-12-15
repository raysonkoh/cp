#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

double INF = 10000.0;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    map<int, vector<pair<double, int>>> adjList;
    for (int j = 0; j < n; j++) {
      vector<pair<double, int>> tmp; // wt-node
      adjList[j] = tmp;
    }

    for (int j = 0; j < m; j++) {
      int a, b;
      double f;
      cin >> a >> b >> f;
      adjList[a].push_back(make_pair(f, b));
      adjList[b].push_back(make_pair(f, a));
    }

    map<int, double> dist;
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;
    for (int j = 1; j < n; j++) {
      dist[j] = INF;
      pq.push(make_pair(INF, j));
    }
    dist[0] = 0;
    pq.push(make_pair(0, 0));

    while (pq.size() > 0) {
      pair<double, int> p = pq.top();
      pq.pop();
      if (p.second == n - 1) {
        break;
      }
      vector<pair<double, int>> neis = adjList.find(p.second)->second;
      for (int k = 0; k < neis.size(); k++) {
        pair<double, int> nei = neis[k];
        double neidist = dist.find(nei.second)->second;
        double newdist = p.first - log2(nei.first);
        if (newdist < neidist) {
          dist[nei.second] = newdist;
          pq.push(make_pair(newdist, nei.second));
        }
      }
    }

    double resdist = dist[n - 1];
    resdist = pow(2, -1 * resdist);
    cout << fixed << setprecision(4) << resdist << endl;
  }
}
