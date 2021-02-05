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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    int maxEle = *max_element(v.begin(), v.end());
    if (k >= maxEle * n) {
      cout << -1 << '\n';
    } else {
      int last;
      while (k > 0) {
        bool end = true;
        for (int i = 0; i < n - 1; i++) {
          if (v[i] >= v[i + 1]) {
            continue;
          }

          v[i]++;
          last = i;
          k--;
          end = false;
          break;
        }

        if (end) {
          last = -1;
          break;
        }
      }

      cout << (last == -1 ? last : last + 1) << '\n';
    }
  }
}
