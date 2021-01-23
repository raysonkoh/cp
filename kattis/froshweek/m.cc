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
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-11;

using namespace std;

long long mergeAndCount(vector<long long> &v, int lo, int hi) {
  /*
  cout << "lo: " << lo << " hi: " << hi << endl;
  cout << "before: " << endl;
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
  */

  if (lo == hi) {
    return 0;
  } else if (lo == hi - 1) {
    if (v[lo] > v[hi]) {
      swap(v[lo], v[hi]);
      return 1;
    }
    return 0;
  }

  int mid = lo + (hi - lo) / 2;
  long long first = mergeAndCount(v, lo, mid);
  long long second = mergeAndCount(v, mid + 1, hi);
  int i = lo;
  int j = mid + 1;

  long long n = 0;
  while (i <= mid && j <= hi) {
    long long a = v[i];
    long long b = v[j];
    if (a < b) {
      i++;
    } else {
      n += mid - i + 1;
      j++;
    }
  }

  sort(v.begin() + lo, v.begin() + hi + 1);
  /*
  cout << "after: " << endl;
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
  cout << "first: " << first << " second: " << second << " n: " << n << endl;
  */
  return first + second + n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  long long res = mergeAndCount(v, 0, n - 1);
  cout << res << '\n';
}