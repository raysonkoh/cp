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

// start with 2, then i += 2, divide by i until indivisible by i
class PrimeFact {
 public:
  int number;
  PrimeFact(int n) : number(n) {}
  map<int, int> findPrimeFacts() {
    int n = number;
    map<int, int> res;
    while (n % 2 == 0) {
      if (res.find(2) == res.end()) {
        res[2] = 0;
      }
      res[2]++;
      n /= 2;
    }
    for (int i = 3; i <= sqrt(number); i += 2) {
      while (n % i == 0) {
        if (res.find(i) == res.end()) {
          res[i] = 0;
        }
        res[i]++;
        n /= i;
      }
    }
    if (n > 2) {
      res[n] = 1;
    }
    return res;
  }
};

// prime seive - fast for < 10^9
class PrimeSeive {
 public:
  vector<bool> v;
  PrimeSeive(int n) { v.assign(n + 1, true); }
  void run() {
    v[0] = false;
    v[1] = false;
    int divisor = 2;
    while (divisor < v.size() && divisor * divisor < v.size()) {
      if (v[divisor]) {
        for (int i = divisor * divisor; i < v.size(); i += divisor) {
          v[i] = false;
        }
      }
      divisor++;
    }
  }
  bool query(int x) { return v[x]; }
  int getCountPrimes() {
    int countPrimes = 0;
    for (int i = 2; i < v.size(); i++) {
      if (v[i])
        countPrimes++;
    }
    return countPrimes;
  }
};

int reduce(int x) {
  int res = 0;
  PrimeFact pf(x);
  for (auto [xx, ct] : pf.findPrimeFacts()) {
    res += xx * ct;
  }
  return res;
}

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
  // PrimeSeive ps(1e9 + 1);
  // ps.run();
  int n;
  while (cin >> n) {
    if (n == 4) break;
    long long num = 1;
    while (true) {
      int tmp = reduce(n);
      if (n == tmp) break;
      n = tmp;
      num++;
    }
    cout << n << " " << num << '\n';
  }
}
