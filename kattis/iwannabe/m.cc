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
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<pair<long long, int>> a(n);
  vector<pair<long long, int>> d(n);
  vector<pair<long long, int>> h(n);
  for (int i = 0; i < n; i++) {
    long long aa, dd, hh;
    cin >> aa >> dd >> hh;
    a[i] = {aa, i};
    d[i] = {dd, i};
    h[i] = {hh, i};
  }
  sort(a.rbegin(), a.rend());
  sort(d.rbegin(), d.rend());
  sort(h.rbegin(), h.rend());
  set<int> s;
  for (int i = 0; i < k; i++) {
    s.insert(a[i].second);
    s.insert(d[i].second);
    s.insert(h[i].second);
  }

  /*
  for (auto x : s)
    cout << x << " ";
  */
  cout << endl;

  cout << s.size() << '\n';
}
