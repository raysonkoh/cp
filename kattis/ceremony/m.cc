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
  int n;
  cin >> n;
  multiset<long long, greater<long long>> s;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s.insert(x);
  }
  long long res = 0;
  long long floors = 0;
  while (s.size() > 0) {
    long long maxx = *s.begin();
    if (maxx - floors > s.size()) {
      // cout << "erased: " << maxx << endl;
      s.erase(s.find(maxx));
    } else {
      floors++;
      while (s.size() > 0 && *s.rbegin() == floors) {
        // cout << "erased: " << floors << endl;
        s.erase(s.find(floors));
      }
    }
    res++;
  }
  cout << res << '\n';
}
