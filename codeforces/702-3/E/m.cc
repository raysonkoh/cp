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
    int n;
    cin >> n;
    vector<long long> v(n);
    map<long long, int> freq;
    long long maxEle = -1;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (freq.count(v[i]) == 0)
        freq[v[i]] = 0;
      freq[v[i]]++;
      maxEle = max(maxEle, v[i]);
    }

    map<long long, long long> prefixSum;
    for (auto [a, b] : freq) {
      if (prefixSum.size() == 0) {
        prefixSum[a] = a * b;
      } else {
        prefixSum[a] += prev(prefixSum.end())->second + a * b;
      }
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (v[i] >= maxEle) {
        res.push_back(i);
        continue;
      }
      long long tmp = v[i];
      while (tmp < maxEle) {
        auto it = prefixSum.lower_bound(tmp);
        if (it->first > tmp) {
          if (it == prefixSum.begin()) {
            continue;
          } else {
            it = prev(it);
          }
        }

        if (it->second == tmp)
          break;
        tmp = it->second;
      }
      if (tmp >= maxEle) {
        res.push_back(i);
      }
    }
    cout << res.size() << '\n';
    for (auto x : res)
      cout << x + 1 << " ";
    cout << '\n';
  }
}
