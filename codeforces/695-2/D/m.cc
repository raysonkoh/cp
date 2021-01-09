#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, q;
  cin >> n >> k >> q;

  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<vector<long long>> dp1(n, vector<long long>(k + 1));
  for (int j = 0; j < k + 1; j++) {
    for (int i = 0; i < n; i++) {
      if (j == 0) {
        dp1[i][j] = 1;
      } else {
        dp1[i][j] = 0;
        if (i - 1 >= 0)
          dp1[i][j] = (dp1[i][j] + dp1[i - 1][j - 1]) % ((long long)(1e9 + 7));
        if (i + 1 < n)
          dp1[i][j] = (dp1[i][j] + dp1[i + 1][j - 1]) % ((long long)(1e9 + 7));
      }
    }
  }

  vector<vector<long long>> dp2(n, vector<long long>(k + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k + 1; j++) {
      dp2[i][j] = (dp1[i][j] * dp1[i][k - j]) % ((long long)1e9 + 7);
    }
  }

  vector<long long> contrib(n, 0);
  long long S = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k + 1; j++) {
      contrib[i] = (contrib[i] + dp2[i][j]) % ((long long)1e9 + 7);
    }

    S += (contrib[i] * v[i]) % ((long long)1e9 + 7);
    S %= (long long)(1e9 + 7);
  }

  while (q--) {
    int i;
    long long x;
    cin >> i >> x;
    i--;
    long long delta = x - v[i];
    S += delta * contrib[i];
    S %= (long long)(1e9 + 7);

    if (S < 0)
      S += (1e9 + 7);

    cout << S << '\n';
    v[i] = x;
  }
}
