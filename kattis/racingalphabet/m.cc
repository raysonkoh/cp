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

int indx(char c) {
  if (c == ' ') {
    return 26;
  } else if (c == '\'') {
    return 27;
  } else {
    return c - 'A';
  }
}

int shortestDist(int src, int dst) {
  if (src <= dst) {
    return min(dst - src, (src + 28) - dst);
  } else {
    return shortestDist(dst, src);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    char curr = s.at(0);
    double res = 1.0;
    for (int j = 1; j < s.length(); j++) {
      char c = s.at(j);
      int shortest = shortestDist(indx(curr), indx(c));
      // cout << "curr: " << curr << " indx: " << indx(curr) << " c: " << c << " indx: " << indx(c) << " dist: " << shortest << '\n';
      res = res + (shortest * M_PI * 60) / (28.0 * 15.0) + 1.0;
      curr = c;
    }
    cout << fixed << setprecision(7) << res << '\n';
  }
}
