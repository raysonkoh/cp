#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
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
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long p, a, b, c;
    cin >> p >> a >> b >> c;
    if (p % a == 0 || p % b == 0 || p % c == 0) {
      cout << 0 << '\n';
      continue;
    }
    long long qa = p / a;
    long long qb = p / b;
    long long qc = p / c;
    cout << min({(qa + 1) * a, (qb + 1) * b, (qc + 1) * c}) - p << '\n';
  }
}
