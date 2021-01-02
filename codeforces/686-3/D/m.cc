#include <cmath>
#include <iostream>
#include <map>

using namespace std;

class PrimeFact {
public:
  long long number;
  PrimeFact(long long n) : number(n) {}
  map<long long, long long> findPrimeFacts() {
    long long n = number;
    map<long long, long long> res;
    while (n % 2 == 0) {
      if (res.find(2) == res.end()) {
        res[2] = 0;
      }
      res[2]++;
      n /= 2;
    }
    for (long long i = 3; i <= sqrt(number); i += 2) {
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
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    PrimeFact primeFact(n);
    map<long long, long long> m = primeFact.findPrimeFacts();
    long long maxCt = 0;
    long long best = 0;
    for (auto &[num, ct] : m) {
      if (ct > maxCt) {
        maxCt = ct;
        best = num;
      }
    }
    long long tolMul = 1;

    cout << maxCt << "\n";

    for (long long i = 0; i < maxCt - 1; i++) {
      tolMul *= best;
      cout << best << " ";
    }

    cout << n / tolMul << "\n";
  }
}
