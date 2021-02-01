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
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      int w;
      cin >> w;
      long long tmp = 0;
      while (w--) {
        long long x;
        cin >> x;
        tmp += x;
      }
      v[i] = tmp;
    }
    sort(v.begin(), v.end());
    long long wait = 0;
    for (int i = 0; i < v.size(); i++) {
      if (i > 0) {
        v[i] += v[i - 1];
      }
      wait += v[i];
    }

    double res = (double)wait / (double)v.size();
    cout << fixed << setprecision(6) << res << '\n';
  }
}
