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
    for (int i = 0; i < k - 3; i++) {
      n--;
      cout << 1 << ' ';
    }
    k = 3;
    if (n % 2 == 1) {
      n--;
      cout << n / 2 << " " << n / 2 << " " << 1 << '\n';
    } else {
      // even
      if (n % 4 == 0) {
        cout << n / 2 << " " << n / 4 << " " << n / 4 << '\n';
      } else {
        cout << (n - 1) / 2 << " " << (n - 1) / 2 << " " << 2 << '\n';
      }
    }
  }
}
