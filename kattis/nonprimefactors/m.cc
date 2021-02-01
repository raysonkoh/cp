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

class PrimeSeive {
 public:
  vector<bool> v;
  PrimeSeive(int n) { v.assign(n + 1, true); }
  set<int> run() {
    v[0] = false;
    v[1] = false;
    int divisor = 2;
    set<int> res;
    while (divisor < v.size() && divisor * divisor < v.size()) {
      if (v[divisor]) {
        res.insert(divisor);
        for (int i = divisor * divisor; i < v.size(); i += divisor) {
          v[i] = false;
        }
      }
      divisor++;
    }
    while (divisor < v.size()) {
      if (v[divisor]) {
        res.insert(divisor);
      }
      divisor++;
    }
    return res;
  }
  bool query(int x) { return v[x]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  PrimeSeive ps(3e6);
  set<int> primes = ps.run();
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    int tol = 1;
    int num = 0;
    for (int p : primes) {
      int tmp = 0;
      while (x % p == 0) {
        x /= p;
        tmp++;
      }
      if (tmp > 0)
        num++;
      tol = tol * (tmp + 1);
      if (x == 1)
        break;
    }
    cout << tol - num << '\n';
  }
}
