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
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, k;
  cin >> a >> b >> k;
  vector<bool> v1(a + b, false);
  vector<bool> v2(a + b, false);

  if (b == 1) {
    if (k > 0) {
      cout << "No\n";
      return 0;
    }
    cout << "Yes\n";
    v1[0] = true;
    v2[0] = true;
    for (auto x : v1)
      cout << x;
    cout << '\n';
    for (auto x : v2)
      cout << x;
    cout << '\n';
    return 0;
  }

  v2[a + b - 1] = true;
  if (a + b - 1 - k < 0) {
    cout << "No\n";
    return 0;
  }
  v1[a + b - 1 - k] = true;
  int b1 = b - 1;
  int b2 = b - 1;
  if (v1[0] && !v2[0]) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; (b1 > 0 && b2 > 0) && i < v1.size(); i++) {
    if (i == a + b - 1 || i == a + b - 1 - k)
      continue;

    if (!v1[i] && !v2[i]) {
      v1[i] = true;
      v2[i] = true;
      b1--;
      b2--;
    }
  }
  if (b1 != 0 || b2 != 0) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    for (auto x : v1)
      cout << x;
    cout << '\n';
    for (auto x : v2)
      cout << x;
    cout << '\n';
  }
}
