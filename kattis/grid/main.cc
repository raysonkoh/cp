#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      v[i][j] = s.at(j) - '0';
    }
  }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq; // (dist, i, j)
  tuple<int, int, int> initial = make_tuple(0, 0, 0);
  pq.push(initial);

  while (pq.size() > 0) {
    tuple<int, int, int> t = pq.top();
    pq.pop();
    int d = get<0>(t);
    int i = get<1>(t);
    int j = get<2>(t);
    int digit = v[i][j];
    // cout << d << " " << i << " " << j << " digit: " << digit << endl;

    if (i - digit >= 0 && d + 1 < dist[i - digit][j]) {
      tuple<int, int, int> next = make_tuple(d + 1, i - digit, j);
      pq.push(next);
      dist[i - digit][j] = d + 1;
    }
    if (i + digit < n && d + 1 < dist[i + digit][j]) {
      tuple<int, int, int> next = make_tuple(d + 1, i + digit, j);
      pq.push(next);
      dist[i + digit][j] = d + 1;
    }
    if (j - digit >= 0 && d + 1 < dist[i][j - digit]) {
      tuple<int, int, int> next = make_tuple(d + 1, i, j - digit);
      pq.push(next);
      dist[i][j - digit] = d + 1;
    }
    if (j + digit < m && d + 1 < dist[i][j + digit]) {
      tuple<int, int, int> next = make_tuple(d + 1, i, j + digit);
      pq.push(next);
      dist[i][j + digit] = d + 1;
    }
  }

  if (dist[n - 1][m - 1] != 1e9) {
    cout << dist[n - 1][m - 1] << endl;
  } else {
    cout << -1 << endl;
  }
}