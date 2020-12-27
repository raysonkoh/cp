#include "prime_fact.cc"
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

// find primeFact, S(a^b * c^d) = S(a^b) * S(c^d)
class SumDiv {
public:
  PrimeFact primeFact;
  SumDiv(int n) : primeFact(PrimeFact(n)) {}
  int calculateSumDiv() {
    map<int, int> m = primeFact.findPrimeFacts();
    int res = 1;
    for (auto it : m) {
      int a = it.first;
      int b = it.second;
      res *= (pow(a, b + 1) - 1) / (a - 1);
    }
    return res;
  }
};