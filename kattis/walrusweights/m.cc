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

bool isBetter(int a, int b) {
  if (a >= 1000 && b <= 1000) {
    return a - 1000 <= 1000 - b;
  }
  return abs(a - 1000) < abs(b - 1000);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  set<int> s;
  int best = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    set<int> tmp;
    for (auto k : s) {
      int newVal = k + x;
      if (isBetter(newVal, best)) {
        best = newVal;
        tmp.insert(newVal);
      } else {
        if (newVal <= 1000) {
          tmp.insert(newVal);
        }
      }
    }

    for (auto k : tmp) {
      s.insert(k);
    }

    if (isBetter(x, best)) {
      best = x;
    }
    s.insert(x);
  }

  cout << best << '\n';
}
