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
    long long n;
    cin >> n;
    long long res = 0;
    for (long long a = 2; (a * a - 1) / 2 <= n; a++) {
      long long numer = (a * a - 1);
      if (numer % 2 == 0) {
        long long b = numer / 2;
        long long c = a * a - b;
        if (c <= n)
          res++;
      }
    }
    cout << res << '\n';
  }
}
