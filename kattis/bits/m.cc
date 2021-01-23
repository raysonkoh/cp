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

int countNumOnes(long long x) {
  long long curr = 1;
  int res = 0;
  for (int i = 0; i < 32; i++) {
    if (x & curr) {
      res++;
    }
    curr *= 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int res = 0;
    int curr = 0;
    for (int i = 0; i < s.length(); i++) {
      int tmp = s.at(i) - '0';
      curr += tmp;
      res = max(res, countNumOnes(curr));
      curr *= 10;
    }
    cout << res << '\n';
  }
}