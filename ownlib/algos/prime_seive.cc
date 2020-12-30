#include <iostream>
#include <vector>

using namespace std;

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