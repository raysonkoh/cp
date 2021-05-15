#include <iostream>
#include <vector>

using namespace std;

const long long P = 1e9 + 7;

class NChooseK {
public:
  vector<long long> fact;
  vector<long long> factInv;

  NChooseK(int n) {
    fact.assign(n + 1, 1);
    factInv.assign(n + 1, 1);
    init();
  }
  void init() {
    for (int i = 1; i < fact.size(); i++) {
      fact[i] = (fact[i - 1] * i) % P;
      factInv[i] = invMod(fact[i]);
    }
  }
  long long invMod(long long x) {
    // Fermat Little Thm: a^p = a (mod p), p is prime
    // thus, a^{p - 1} = 1 (mod p)
    // --> a * invMod(a) = 1 = a^{p - 1} (mod p)
    // --> invMod(a) = a^{p - 2} (mod p)
    return fastMod(x, P - 2);
  }
  long long fastMod(long long a, long long exp) {
    if (exp == 0) {
      return 1;
    } else if (exp == 1) {
      return a % P;
    }

    long long mid = exp / 2;
    long long tmp = fastMod(a, mid);
    if (exp % 2 == 0) {
      return (tmp * tmp) % P;
    } else {
      return ((tmp * tmp) % P * a) % P;
    }
  }
  long long query(int n, int k) {
    // nCk = n! / (k! * (n - k)!)
    return (((fact[n] * factInv[k]) % P) * factInv[n - k]) % P;
  }
};

class NChooseKTable {
public:
  vector<vector<long long>> binomTable;
  NChooseKTable(int nMax, int kMax) {
    binomTable.assign(nMax + 1, vector<long long>(kMax + 1));
    initBinomTable();
  }
  void initBinomTable() {
    for (long long i = 0; i < binomTable.size(); i++) {
      for (long long j = 0; j < binomTable[i].size(); j++) {
        if (j == 0) {
          binomTable[i][j] = 1;
        } else if (i == 0) {
          binomTable[i][j] = 0;
        } else if (j == 1) {
          binomTable[i][j] = i % P;
        } else {
          binomTable[i][j] = (binomTable[i - 1][j] + binomTable[i - 1][j - 1]) % P;
        }
      }
    }
  }
  long long query(int n, int k) { return binomTable[n][k]; }
};

int main() {
  NChooseK nCk(1000);
  NChooseKTable brute(1000, 1000);
  for (int n = 0; n < 1000; n++) {
    for (int k = n - 1; k >= 0; k--) {
      long long res = nCk.query(n, k);
      long long expect = brute.query(n, k);
      if (res != expect)
        cout << "n: " << n << " k: " << k << " res: " << res << " expect: " << expect << endl;
    }
  }
}
