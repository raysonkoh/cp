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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<long long> prefixSum(n);
    map<long long, set<long long>> prefixSumMap;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (i == 0) {
        prefixSum[i] = v[i];
      } else {
        prefixSum[i] = prefixSum[i - 1] + v[i];
      }
      if (prefixSumMap.count(prefixSum[i]) == 0) {
        prefixSumMap[prefixSum[i]] = set<long long>();
      }

      prefixSumMap[prefixSum[i]].insert(i);
    }

    if (prefixSumMap.count(0) == 0) {
      prefixSumMap[0] = set<long long>();
    }
    prefixSumMap[0].insert(-1);

    long long res = 0;
    for (int i = 0; i < n; i++) {
      long long ps = prefixSum[i];
      long long other = ps - 47;
      // cout << "i: " << i << " ps: " << ps << " other: " << other << endl;
      if (prefixSumMap.count(other) == 0) continue;

      set<long long> s = prefixSumMap[other];
      /*
      for (auto x : s) {
        cout << x << " ";
      }
      cout << endl;
      */
      int numSmallerIndx = distance(s.begin(), s.lower_bound(i));
      // cout << "numSmaller: " << numSmallerIndx << endl;
      res += numSmallerIndx;
    }
    cout << res << '\n';
  }
}
