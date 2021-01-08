#include <iostream>
#include <numeric>

using namespace std;

pair<long long, long long> add(long long x1, long long y1, long long x2, long long y2) {
  long long denom = y1 * y2;
  long long numer = x1 * y2 + x2 * y1;

  long long a = abs(numer);
  long long b = abs(denom);
  long long g = gcd(a, b);
  a /= g;
  b /= g;

  if (numer >= 0 && denom >= 0) {
    // ok
  } else if (numer < 0 && denom >= 0) {
    a = -a;
  } else if (numer >= 0 && denom < 0) {
    a = -a;
  } else {
    // both neg
  }
  return {a, b};
}

pair<long long, long long> mul(long long x1, long long y1, long long x2, long long y2) {
  long long denom = y1 * y2;
  long long numer = x1 * x2;

  long long a = abs(numer);
  long long b = abs(denom);
  long long g = gcd(a, b);
  a /= g;
  b /= g;

  if (numer >= 0 && denom >= 0) {
    // ok
  } else if (numer < 0 && denom >= 0) {
    a = -a;
  } else if (numer >= 0 && denom < 0) {
    a = -a;
  } else {
    // both neg
  }
  return {a, b};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long x1, y1, x2, y2;
    char op;
    cin >> x1 >> y1 >> op >> x2 >> y2;
    switch (op) {
    case '+': {
      auto [a, b] = add(x1, y1, x2, y2);
      cout << a << " / " << b << '\n';
      break;
    }
    case '-': {
      auto [a, b] = add(x1, y1, -x2, y2);
      cout << a << " / " << b << '\n';
      break;
    }
    case '*': {
      auto [a, b] = mul(x1, y1, x2, y2);
      cout << a << " / " << b << '\n';
      break;
    }
    case '/': {
      auto [a, b] = mul(x1, y1, y2, x2);
      cout << a << " / " << b << '\n';
      break;
    }
    }
  }
}
