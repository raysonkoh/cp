#include <iostream>
#include <numeric>

using namespace std;

/*
  a > b
  Note that using std::gcd from <numeric> header is faster!!
*/
long long gcd(long long a, long long b) {
  if (a <= b)
    return gcd(b, a);

  if (b == 0)
    return a;

  return gcd(b, a % b);
}
