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
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s.insert(x);
    }

    int smallest = 0;
    while (s.count(smallest) > 0) {
      smallest++;
    }
    int prev = -1;
    int addition = 0;
    for (int i = 0; i < k; i++) {
      int maxx = *s.rbegin();
      int add = (smallest + maxx + 2 - 1) / 2;
      if (smallest > maxx) {
        addition += k - i;
        break;
      }
      if (add == prev) {
        break;
      }
      s.insert(add);
      while (s.count(smallest) > 0) {
        smallest++;
      }
      prev = add;
    }

    cout << s.size() + addition << '\n';
  }
}
