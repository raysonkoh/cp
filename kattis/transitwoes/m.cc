#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11
#define LSOne(S) ((S) & -(S))

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int s, t, n;
  cin >> s >> t >> n;
  vector<int> d(n + 1);
  for (int i = 0; i < n + 1; i++)
    cin >> d[i];
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vector<int> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];

  int i = 0;
  while (s <= t) {
    s += d[i];
    if (i == n) {
      cout << (s <= t ? "yes\n" : "no\n");
      return 0;
    }

    if (s % c[i] == 0) {
      s += b[i];
      i++;
    } else {
      int tmp = c[i];
      while (tmp < s) {
        tmp += c[i];
      }
      s = tmp;
      s += b[i];
      i++;
    }
  }

  cout << "no\n";
}
