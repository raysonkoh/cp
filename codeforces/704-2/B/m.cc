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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    set<int> s;
    for (int i = 1; i <= n; i++)
      s.insert(i);
    int i = 0;
    int j = n - 1;
    vector<int> res(n);
    while (i < n) {
      int origj = j;
      while (j - 1 >= 0 && v[j] != *s.rbegin()) {
        j--;
      }
      for (int tmpj = j; tmpj <= origj; tmpj++) {
        s.erase(v[tmpj]);
        res[i] = v[tmpj];
        i++;
      }
      j--;
    }
    for (int x : res)
      cout << x << " ";
    cout << '\n';
  }
}
