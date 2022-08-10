using namespace std;

// inverse of a mod b
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

// inverse of a mod b, b is prime : mod_pow(a, b-2)
long long mod_pow(long long a, long long x) {
  if (x == 0)
    return 1;

  long long tmp = mod_pow(a, x / 2);
  if (x % 2 == 0) {
    return (tmp * tmp) % MOD;
  } else {
    return (((tmp * tmp) % MOD) * a) % MOD;
  }
}
