#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long m, n, t;
  cin >> m >> n >> t;
  bool ok = true;
  switch (t) {
  case 1: {
    double tmp = 0;
    double tmpM = log10(m);
    for (int i = 2; i <= n; i++) {
      tmp += log10(i);
      if (tmp > tmpM) {
        ok = false;
        break;
      }
    }
    break;
  }
  case 2: {
    long long tmp = 1;
    for (int i = 0; i < n; i++) {
      tmp *= 2;
      if (tmp > m) {
        ok = false;
        break;
      }
    }
    break;
  }
  case 3: {
    long long tmp = 1;
    for (int i = 0; i < 4; i++) {
      tmp *= n;
      if (tmp > m) {
        ok = false;
        break;
      }
    }
    break;
  }
  case 4: {
    long long tmp = 1;
    for (int i = 0; i < 3; i++) {
      tmp *= n;
      if (tmp > m) {
        ok = false;
        break;
      }
    }
    break;
  }
  case 5: {
    long long tmp = 1;
    for (int i = 0; i < 2; i++) {
      tmp *= n;
      if (tmp > m) {
        ok = false;
        break;
      }
    }
    break;
  }
  case 6:
    ok = (n * log2(n)) <= m;
    break;
  case 7:
    ok = n <= m;
    break;
  }
  cout << (ok ? "AC" : "TLE") << "\n";
}
