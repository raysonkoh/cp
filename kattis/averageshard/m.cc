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
  int t;
  cin >> t;
  while (t--) {
    int ncs, ne;
    cin >> ncs >> ne;
    multiset<int> ms;
    long long tolcs = 0;
    for (int i = 0; i < ncs; i++) {
      long long x;
      cin >> x;
      tolcs += x;
      ms.insert(x);
    }
    long long tole = 0;
    for (int i = 0; i < ne; i++) {
      long long x;
      cin >> x;
      tole += x;
    }
    long long lo, hi;
    if (tolcs % ncs == 0) {
      hi = (tolcs / ncs) - 1;
    } else {
      hi = tolcs / ncs;
    }

    lo = tole / ne + 1;

    int res = 0;
    for (long long i = lo; i <= hi; i++) {
      while (ms.find(i) != ms.end()) {
        res++;
        ms.erase(ms.find(i));
      }
    }
    cout << res << '\n';
  }
}
