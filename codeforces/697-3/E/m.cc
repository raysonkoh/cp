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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  NChooseK nck(2000);
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