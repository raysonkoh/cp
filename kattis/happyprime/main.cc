#include <iostream>
#include <set>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int k, m;
    cin >> k >> m;
    PrimeSeive primeSeive(m);
    primeSeive.run();
    cout << k << " " << m << " ";
    if (!primeSeive.query(m)) {
      cout << "NO"
           << "\n";
      continue;
    }
    set<int> seen;
    seen.insert(m);
    bool isHappy = true;
    while (m != 1) {
      string ms = to_string(m);
      m = 0;
      for (char c : ms) {
        int x = c - '0';
        m += x * x;
      }
      if (seen.find(m) == seen.end()) {
        seen.insert(m);
      } else {
        isHappy = false;
        break;
      }
    }
    cout << (isHappy ? "YES" : "NO") << "\n";
  }
}