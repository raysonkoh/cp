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

class NChooseK {
 public:
  vector<long long> fact;
  vector<long long> factInv;

  NChooseK(int n) {
    fact.assign(n + 1, 1);
    factInv.assign(n + 1, 1);
    init();
  }
  void init() {
    for (int i = 1; i < fact.size(); i++) {
      fact[i] = (fact[i - 1] * i) % P;
      factInv[i] = invMod(fact[i]);
    }
  }
  long long invMod(long long x) {
    // Fermat Little Thm: a^p = a (mod p), p is prime
    // thus, a^{p - 1} = 1 (mod p)
    // --> a * invMod(a) = 1 = a^{p - 1} (mod p)
    // --> invMod(a) = a^{p - 2} (mod p)
    return fastMod(x, P - 2);
  }
  long long fastMod(long long a, long long exp) {
    if (exp == 0) {
      return 1;
    } else if (exp == 1) {
      return a % P;
    }

    long long mid = exp / 2;
    long long tmp = fastMod(a, mid);
    if (exp % 2 == 0) {
      return (tmp * tmp) % P;
    } else {
      return ((tmp * tmp) % P * a) % P;
    }
  }
  long long query(int n, int k) {
    // nCk = n! / (k! * (n - k)!)
    return (((fact[n] * factInv[k]) % P) * factInv[n - k]) % P;
  }
};

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  NChooseK nck(50);
  int n;
  cin >> n;
  if (n == 0 || n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += nck.query(n, i);
  }
  cout << ans << '\n';
}
