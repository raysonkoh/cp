#include <iostream>
#include <vector>

#define LSOne(S) ((S) & -(S))

using namespace std;

// 1-indexed
class BIT {
public:
  vector<long long> v;
  BIT(int n) { v.assign(n + 1, 0); }

  void update(int x, long long delta) {
    for (; x < v.size(); x += LSOne(x)) {
      v[x] += delta;
    }
  }

  long long prefixSum(int x) {
    long long res = 0;
    for (; x; x -= LSOne(x)) {
      res += v[x];
    }
    return res;
  }

  long long sumRange(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }
};