#include <iostream>
#include <set>
#include <vector>

using namespace std;

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
  set<int> getPrimes() {
    set<int> res;
    for (int i = 0; i < v.size(); i++) {
      if (v[i]) {
        res.insert(i);
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  PrimeSeive ps(32000);
  ps.run();
  set<int> primes = ps.getPrimes();
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    vector<pair<int, int>> tmp;
    for (int prime : primes) {
      if (prime > x / 2) {
        break;
      }
      if (primes.find(x - prime) != primes.end()) {
        tmp.push_back(make_pair(prime, x - prime));
      }
    }
    cout << x << " has " << tmp.size() << " representation(s)\n";
    for (auto p : tmp) {
      cout << p.first << "+" << p.second << "\n";
    }
    cout << "\n";
  }
}