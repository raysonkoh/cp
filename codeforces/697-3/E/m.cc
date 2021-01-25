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
class NChooseK {
public:
  vector<vector<long long>> binomTable;
  NChooseK(int nMax, int kMax) {
    binomTable.assign(nMax + 1, vector<long long>(kMax + 1));
    initBinomTable();
  }
  void initBinomTable() {
    for (long long i = 0; i < binomTable.size(); i++) {
      for (long long j = 0; j < binomTable[i].size(); j++) {
        if (j == 0) {
          binomTable[i][j] = 1;
        } else if (i == 0) {
          binomTable[i][j] = 0;
        } else if (j == 1) {
          binomTable[i][j] = i;
        } else {
          binomTable[i][j] = (binomTable[i - 1][j] + binomTable[i - 1][j - 1]) % P;
        }
      }
    }
  }
  long long query(int n, int k) { return binomTable[n][k]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  NChooseK nck(1000, 1000);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int, int> count;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
      if (count.count(x) == 0) {
        count[x] = 0;
      }
      count[x]++;
    }
    sort(v.rbegin(), v.rend());
    map<int, int> chosen;
    for (int i = 0; i < k; i++) {
      if (chosen.count(v[i] == 0))
        chosen[v[i]] = 0;
      chosen[v[i]]++;
    }

    long long res = 1;
    for (auto [key, val] : chosen) {
      int ct = count[key];
      res = (res * nck.query(ct, val)) % P;
    }
    cout << res << '\n';
  }
}