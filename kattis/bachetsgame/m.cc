#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
    }
    vector<int> dp(n + 1, -1); // 0 - Stan, 1 - Ollie
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      bool foundSol = false;
      for (int k : v) {
        if (i - k >= 0 && (dp[i - k] == 0)) {
          dp[i] = 1;
          foundSol = true;
          break;
        }
      }

      if (!foundSol) {
        dp[i] = 0;
      }
    }

    cout << (dp[n] == 1 ? "Stan " : "Ollie ") << "wins\n";
  }
}
