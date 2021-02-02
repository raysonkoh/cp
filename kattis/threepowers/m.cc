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
  long long n;
  vector<long long> v(67);
  v[1] = 1;
  for (int i = 2; i < v.size(); i++) {
    v[i] = 3 * v[i - 1];
  }
  while (cin >> n) {
    if (n == 0)
      break;

    n--;
    vector<int> res;
    long long exp = 1;
    for (int i = 1; exp <= n; i++, exp *= 2) {
      if (n & exp) {
        res.push_back(v[i]);
      }
    }
    for (int x : res)
      cout << x << " ";
    cout << '\n';
  }
}
