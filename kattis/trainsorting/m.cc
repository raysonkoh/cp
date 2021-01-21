#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11
#define LSOne(S) ((S) & -(S))

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  vector<int> lis(n, 1); // longest incr subseq starting from pos i
  lis[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (v[i] < v[j]) {
        lis[i] = max(lis[i], lis[j] + 1);
      }
    }
  }

  vector<int> lds(n, 1); // longest decr subseq starting from pos i
  lds[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (v[i] > v[j]) {
        lds[i] = max(lds[i], lds[j] + 1);
      }
    }
  }

  int res = 1;
  for (int i = 0; i < n; i++) {
    res = max(res, lis[i] + lds[i] - 1);
  }

  cout << res << '\n';
}
