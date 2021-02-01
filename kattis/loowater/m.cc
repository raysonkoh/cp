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
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    vector<int> heads(n);
    vector<int> knights(m);
    for (int i = 0; i < n; i++)
      cin >> heads[i];
    for (int i = 0; i < m; i++)
      cin >> knights[i];

    sort(heads.begin(), heads.end());
    sort(knights.begin(), knights.end());
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < heads.size() && j < knights.size()) {
      if (knights[j] >= heads[i]) {
        res += knights[j];
        i++;
        j++;
      } else {
        j++;
      }
    }
    if (i == heads.size()) {
      cout << res << '\n';
    } else {
      cout << "Loowater is doomed!" << '\n';
    }
  }
}
