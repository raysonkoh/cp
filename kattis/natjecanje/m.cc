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
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, s, r;
  cin >> n >> s >> r;
  set<int> damage;
  for (int i = 0; i < s; i++) {
    int x;
    cin >> x;
    damage.insert(x);
  }
  set<int> reserve;
  for (int i = 0; i < r; i++) {
    int x;
    cin >> x;
    reserve.insert(x);
  }

  int ans = 0;
  for (int x : damage) {
    if (reserve.count(x) > 0) {
      reserve.erase(x);
    } else if (reserve.count(x - 1) > 0) {
      reserve.erase(x - 1);
    } else if (reserve.count(x + 1) > 0) {
      reserve.erase(x + 1);
    } else {
      ans++;
    }
  }
  cout << ans << '\n';
}
