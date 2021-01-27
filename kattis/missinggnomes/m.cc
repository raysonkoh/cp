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
  cin >> n >> m;
  vector<int> v(m);
  set<int> inV;
  for (int i = 0; i < m; i++) {
    cin >> v[i];
    inV.insert(v[i]);
  }

  int mI = 0;
  int i = 1;
  while (i <= n) {
    if (inV.count(i) > 0) {
      i++;
    } else if (mI < m && v[mI] == i) {
      cout << v[mI] << '\n';
      mI++;
      i++;
    } else if (mI < m && v[mI] < i) {
      cout << v[mI] << '\n';
      mI++;
    } else {
      cout << i << '\n';
      i++;
    }
  }
  for (int i = mI; i < m; i++) {
    cout << v[i] << '\n';
  }
}
