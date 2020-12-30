#include <cmath>
#include <iostream>
#include <map>
#include <vector>

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
