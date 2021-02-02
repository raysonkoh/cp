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

class Primes {
 public:
  vector<long long> numDiv;     // number of divisors of x
  vector<long long> numPrimes;  // number of prime numbers that is a divisor of x
  Primes(int n) {
    numDiv.assign(n + 1, 1);
    numPrimes.assign(n + 1, 0);
  }
  void run() {
    numDiv[0] = 0;
    numDiv[1] = 1;
    numPrimes[0] = 0;
    numPrimes[1] = 0;

    int divisor = 2;
    while (divisor < numDiv.size()) {
      if (numPrimes[divisor] == 0) {
        for (int i = divisor; i < numDiv.size(); i += divisor) {
          int tmp = i;
          long long tmp2 = 0;
          while (tmp % divisor == 0) {
            tmp /= divisor;
            tmp2++;
          }
          numDiv[i] *= (tmp2 + 1);
          numPrimes[i]++;
        }
      }
      divisor++;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Primes pr(2000000);
  pr.run();
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    // cout << "x: " << x << endl;
    // cout << "numDivs: " << pr.numDiv[x] << endl;
    // cout << "numPrimes: " << pr.numPrimes[x] << endl;
    long long res = pr.numDiv[x] - pr.numPrimes[x];
    cout << res << '\n';
  }
}
