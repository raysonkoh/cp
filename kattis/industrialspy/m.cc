#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-9;

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

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  PrimeSeive ps(1e8);
  ps.run();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> exp(s.length());
    exp[0] = 1;
    for (int i = 1; i < exp.size(); i++) {
      exp[i] = exp[i - 1] * 2;
    }
    set<int> ss;
    for (int i = 0; i < exp[exp.size() - 1] * 2; i++) {
      string tmp = "";
      for (int j = 0; j < exp.size(); j++) {
        if (i & exp[j]) {
          tmp.push_back(s.at(j));
        }
      }

      sort(tmp.begin(), tmp.end());

      do {
        string tmps(tmp);
        while (tmps.length() > 0 && tmps.at(0) == '0') {
          tmps = tmps.substr(1);
        }
        if (tmps.length() > 0) {
          int x = stoi(tmps);
          if (ps.query(x)) {
            ss.insert(x);
          }
        }
      } while (next_permutation(tmp.begin(), tmp.end()));
    }
    cout << ss.size() << '\n';
  }
}
