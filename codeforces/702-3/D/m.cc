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
const double EPS = 1e-11;

using namespace std;

void label(vector<int> &v, vector<int> &d, int lo, int hi, int off) {
  if (lo == hi) {
    d[lo] = off;
    return;
  }

  int maxEle = -1;
  int maxIndx = -1;
  for (int i = lo; i <= hi; i++) {
    if (v[i] > maxEle) {
      maxEle = v[i];
      maxIndx = i;
    }
  }
  d[maxIndx] = off;
  if (maxIndx - 1 >= lo)
    label(v, d, lo, maxIndx - 1, off + 1);
  if (maxIndx + 1 <= hi)
    label(v, d, maxIndx + 1, hi, off + 1);
}

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
    vector<int> d(n, 0);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    label(v, d, 0, n - 1, 0);
    for (int i = 0; i < n; i++)
      cout << d[i] << " ";
    cout << '\n';
  }
}
