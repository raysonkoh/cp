#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
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
const double EPS = 1e-11;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<long long> v(n);
    vector<long long> prefixSum(n);
    long long roundSum = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (i == 0)
        prefixSum[i] = v[i];
      else
        prefixSum[i] = prefixSum[i - 1] + v[i];
      roundSum += v[i];
    }

    vector<long long> maxPrefixSum(n);
    for (int i = 0; i < n; i++) {
      if (i == 0)
        maxPrefixSum[i] = prefixSum[i];
      else
        maxPrefixSum[i] = max(maxPrefixSum[i - 1], prefixSum[i]);
    }

    while (m--) {
      long long x;
      cin >> x;
      // impossible case
      if (roundSum <= 0 && maxPrefixSum[n - 1] < x) {
        cout << -1 << ' ';
        continue;
      }

      // either 1 round or > 1 rounds
      if (maxPrefixSum[n - 1] >= x) {
        int indx = lower_bound(maxPrefixSum.begin(), maxPrefixSum.end(), x) - maxPrefixSum.begin();
        cout << indx << ' ';
      } else {
        long long numRounds = (x - maxPrefixSum[n - 1] + roundSum - 1) / roundSum;
        long long res = numRounds * n;
        long long tmp = numRounds * roundSum;
        int indx = lower_bound(maxPrefixSum.begin(), maxPrefixSum.end(), x - tmp) - maxPrefixSum.begin();
        cout << res + indx << " ";
      }
    }
    cout << '\n';
  }
}