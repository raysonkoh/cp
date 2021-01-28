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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> m;
    int maxDuplicates = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (m.count(x) == 0)
        m[x] = 0;
      m[x]++;
      maxDuplicates = max(maxDuplicates, m[x]);
    }
    cout << maxDuplicates << '\n';
  }
}
