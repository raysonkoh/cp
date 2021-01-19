#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11
#define LSOne(S) ((S) & -(S))

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
  PrimeSeive ps(1e8);
  ps.run();

  int t;
  cin >> t;
  while (t--) {
    int d;
    cin >> d;
    int i = 2;
    int first;
    while (true) {
      if (ps.v[i] && i - 1 >= d) {
        first = i;
        i++;
        break;
      }
      i++;
    }

    int second;
    while (true) {
      if (ps.v[i] && i - first >= d) {
        second = i;
        break;
      }
      i++;
    }

    cout << first * second << '\n';
  }
}
