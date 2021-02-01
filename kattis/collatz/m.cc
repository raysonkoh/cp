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

map<long long, long long> gen(long long x) {
  long long i = 0;
  map<long long, long long> res;
  res[x] = 0;
  while (x != 1) {
    i++;
    if (x % 2 == 0) {
      x /= 2;
    } else {
      x = 3 * x + 1;
    }
    res[x] = i;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0)
      break;

    map<long long, long long> va = gen(a);
    long long as, bs;
    long long tmpb = b;
    long long i = 0;
    while (true) {
      if (va.count(tmpb) == 0) {
        if (tmpb % 2 == 0) {
          tmpb = tmpb / 2;
        } else {
          tmpb = tmpb * 3 + 1;
        }
      } else {
        as = va[tmpb];
        bs = i;
        break;
      }
      i++;
    }

    cout << a << " needs " << as << " steps, " << b << " needs " << bs << " steps, they meet at " << tmpb << '\n';
  }
}
