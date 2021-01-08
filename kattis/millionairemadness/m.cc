#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> v(n, vector<long long>(m));
  vector<vector<long long>> dist(n, vector<long long>(m, 1e9));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j];
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
  dist[n - 1][m - 1] = 0;
  pq.push({0, n - 1, m - 1});

  while (pq.size() > 0) {
    auto [d, i, j] = pq.top();
    pq.pop();

    if (i - 1 >= 0) {
      long long di = max(d, max(v[i][j] - v[i - 1][j], 0ll));
      if (di < dist[i - 1][j]) {
        dist[i - 1][j] = di;
        pq.push({di, i - 1, j});
      }
    }

    if (i + 1 < n) {
      long long di = max(d, max(v[i][j] - v[i + 1][j], 0ll));
      if (di < dist[i + 1][j]) {
        dist[i + 1][j] = di;
        pq.push({di, i + 1, j});
      }
    }

    if (j - 1 >= 0) {
      long long di = max(d, max(v[i][j] - v[i][j - 1], 0ll));
      if (di < dist[i][j - 1]) {
        dist[i][j - 1] = di;
        pq.push({di, i, j - 1});
      }
    }

    if (j + 1 < m) {
      long long di = max(d, max(v[i][j] - v[i][j + 1], 0ll));
      if (di < dist[i][j + 1]) {
        dist[i][j + 1] = di;
        pq.push({di, i, j + 1});
      }
    }
  }

  cout << dist[0][0] << '\n';
}