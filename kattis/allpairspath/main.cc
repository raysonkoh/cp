#include <iostream>
#include <vector>

using namespace std;

int INF = 1e9;

void print2d(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, q;
  bool isFirst = true;
  while (cin >> n >> m >> q) {
    // cout << "n: " << n << " m: " << m << " q: " << q;
    if (n == 0 && m == 0 && q == 0) {
      break;
    }

    if (isFirst) {
      isFirst = false;
    } else {
      cout << endl;
    }

    // vector<vector<pair<int, int>>> adjList(n); // (weight, label)
    vector<vector<int>> dp(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
      dp[i][i] = 0;
    }
    // print2d(dp);

    for (int i = 0; i < m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      // adjList[a].push_back(make_pair(w, b));
      // cout << "a: " << a << " b: " << b << " w: " << w << " val: " <<
      // dp[a][b]
      //     << endl;
      dp[a][b] = min(dp[a][b], w);
      // cout << "a: " << a << " b: " << b << " w: " << w << " val: " <<
      // dp[a][b]
      //     << endl;
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          // cout << "i: " << i << " j: " << j << " bef val: " << dp[i][j] <<
          // endl;
          if (dp[i][k] < INF && dp[k][j] < INF) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
          }
          // cout << "i: " << i << " j: " << j << " aft val: " << dp[i][j] <<
          // endl;
        }
      }
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          // cout << "i: " << i << " j: " << j << " bef val: " << dp[i][j] <<
          // endl;
          if (dp[k][k] < 0 && dp[i][k] != INF && dp[k][j] != INF) {
            dp[i][j] = -1 * INF;
          }
          // cout << "i: " << i << " j: " << j << " aft val: " << dp[i][j] <<
          // endl;
        }
      }
    }

    for (int i = 0; i < q; i++) {
      int a, b;
      cin >> a >> b;
      if (dp[a][b] == INF) {
        cout << "Impossible" << endl;
      } else if (dp[a][b] == -1 * INF) {
        cout << "-Infinity" << endl;
      } else {
        cout << dp[a][b] << endl;
      }
    }
  }
}