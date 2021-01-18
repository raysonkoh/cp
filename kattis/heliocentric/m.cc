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
  int e, m;
  int caseNum = 1;
  while (cin >> e >> m) {
    int res = 0;
    while (e != m) {
      e = (e + 1) % 365;
      m = (m + 1) % 687;
      res++;
    }
    cout << "Case " << caseNum << ": " << res << '\n';
    caseNum++;
  }
}
