#include <iostream>

#define LSOne(S) ((S) & -(S))

using namespace std;

long long BIT[5000001];

void update(int x, int n, long long delta) {
  for (; x < n + 1; x += LSOne(x)) {
    BIT[x] += delta;
  }
}

long long prefixSum(int x) {
  long long res = 0;
  for (; x; x -= LSOne(x)) {
    res += BIT[x];
  }
  return res;
}