#include <algorithm>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<long long> b1;
    vector<long long> b2;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++) {
      int b;
      cin >> b;
      if (b == 1) {
        b1.push_back(a[i]);
      } else {
        // 2
        b2.push_back(a[i]);
      }
    }

    sort(b1.rbegin(), b1.rend());
    vector<long long> prefixSum(b1.size());
    for (int i = 0; i < b1.size(); i++) {
      if (i == 0) {
        prefixSum[i] = b1[i];
      } else {
        prefixSum[i] = prefixSum[i - 1] + b1[i];
      }
    }
    sort(b2.rbegin(), b2.rend());
    int indx = lower_bound(prefixSum.begin(), prefixSum.end(), m) - prefixSum.begin();
    int bestCon = 1e9;
    if (indx < b1.size()) {
      bestCon = indx + 1;
    }
    int currCon = 0;
    long long memLost = 0;
    for (int i = 0; i < b2.size(); i++) {
      memLost += b2[i];
      currCon += 2;
      if (memLost >= m) {
        bestCon = min(bestCon, currCon);
        break;
      }
      long long target = m - memLost;
      int indx = lower_bound(prefixSum.begin(), prefixSum.end(), target) - prefixSum.begin();
      if (indx < b1.size()) {
        bestCon = min(bestCon, currCon + indx + 1);
      }
    }
    cout << (bestCon == 1e9 ? -1 : bestCon) << '\n';
  }
}