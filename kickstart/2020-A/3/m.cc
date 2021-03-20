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
  int caseNum = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    long long lo = 1;
    long long hi = v[n - 1] - v[0];
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      int tmpK = k;
      bool can = true;
      for (int i = 1; i < n; i++) {
        long long diff = v[i] - v[i - 1];
        // num to add: ceil(diff / mid) - 1
        long long numToAdd = ((diff + mid - 1) / mid) - 1;
        if (tmpK - numToAdd < 0) {
          can = false;
          break;
        }
        tmpK -= numToAdd;
      }
      if (can) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    cout << "Case #" << caseNum << ": " << lo << '\n';

    caseNum++;
  }
}
