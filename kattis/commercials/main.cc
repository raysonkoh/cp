#include <iostream>
#include <vector>

#define P 1000000007

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, p;
  cin >> n >> p;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x -= p;
    v[i] = x;
  }

  vector<int> dp(n);
  int best = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      dp[i] = v[i];
    } else {
      dp[i] = max(v[i], dp[i - 1] + v[i]);
    }
    best = max(best, dp[i]);
  }
  cout << best << '\n';
}
