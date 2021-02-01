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
const double EPS = 1e-13;

using namespace std;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long x;
  while (cin >> x) {
    if (x == 0)
      break;
    bool neg = false;
    if (x < 0) {
      neg = true;
      x = -x;
    }
    PrimeFact pf(x);
    map<int, int> m = pf.findPrimeFacts();
    int g = 0;
    for (auto [k, v] : m) {
      g = gcd(g, v);
    }

    if (neg && g % 2 == 0) {
      for (int i = g - 1; i >= 1; i -= 2) {
        if (g % i == 0) {
          g = i;
          break;
        }
      }
    }

    cout << (g == 0 ? 1 : g) << '\n';
  }
}
