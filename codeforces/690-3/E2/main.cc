#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

void initBinomTable(vector<vector<long long>> &v) {
  for (long long i = 0; i < v.size(); i++) {
    for (long long j = 0; j < v[i].size(); j++) {
      if (j == 0) {
        v[i][j] = 1;
      } else if (i == 0) {
        v[i][j] = 0;
      } else if (j == 1) {
        v[i][j] = i;
      } else {
        v[i][j] = (v[i - 1][j] + v[i - 1][j - 1]) % MOD;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  vector<vector<long long>> binomTable(2e5 + 1, vector<long long>(100 + 1));
  initBinomTable(binomTable);
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long res = 0;
    // i : min, j : max
    for (int i = 0; i < n; i++) {
      int rightBound = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
      res = (res + binomTable[rightBound - i - 1][m - 1]) % MOD;
    }

    cout << res << "\n";
  }
}