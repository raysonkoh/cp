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
  string cmd;
  map<string, int> m;
  while (cin >> cmd) {
    if (cmd == "define") {
      int x;
      string y;
      cin >> x >> y;
      m[y] = x;
    } else {
      // eval
      string a, cmp, b;
      cin >> a >> cmp >> b;
      if (m.count(a) == 0 || m.count(b) == 0) {
        cout << "undefined\n";
        continue;
      }
      int aval = m[a];
      int bval = m[b];
      bool can;
      if (cmp == "<") {
        can = aval < bval;
      } else if (cmp == ">") {
        can = aval > bval;
      } else {
        // eq
        can = aval == bval;
      }
      cout << (can ? "true" : "false") << '\n';
    }
  }
}
