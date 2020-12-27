#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // find prime factorization
  // S(a^b * c^d) = S(a^b) *  S(c^d)
  // S(a^b) = (a^{b + 1} - 1) / (a - 1)
  int x;
  while (cin >> x) {
    // find prime factorization
    map<int, int> primeFactors;
    int n = x;
    while (n % 2 == 0) {
      if (primeFactors.find(2) == primeFactors.end()) {
        primeFactors[2] = 0;
      }
      primeFactors[2]++;
      n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
      while (n % i == 0) {
        if (primeFactors.find(i) == primeFactors.end()) {
          primeFactors[i] = 0;
        }
        primeFactors[i]++;
        n /= i;
      }
    }
    if (n > 2) {
      primeFactors[n] = 1;
    }
    long long sumDiv = 1;
    for (auto it : primeFactors) {
      int a = it.first;
      int b = it.second;
      int calc = (pow(a, b + 1) - 1) / (a - 1);
      // cout << a << ": " << b << ", calc: " << calc << endl;
      sumDiv *= calc;
    }
    sumDiv -= x;
    // cout << sumDiv << endl;
    if (x == sumDiv) {
      cout << x << " perfect"
           << "\n";

    } else if (abs(x - sumDiv) <= 2) {
      cout << x << " almost perfect"
           << "\n";
    } else {
      cout << x << " not perfect"
           << "\n";
    }
  }
}