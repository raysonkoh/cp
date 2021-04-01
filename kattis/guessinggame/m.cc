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
  int g;
  int lo = 1;
  int hi = 10;
  while (cin >> g) {
    if (g == 0) break;

    string s1, s2;
    cin >> s1 >> s2;
    if (s2 == "high") {
      hi = min(hi, g - 1);
    } else if (s2 == "low") {
      lo = max(lo, g + 1);
    } else if (s2 == "on") {
      cout << ((lo <= hi && lo <= g && g <= hi) ? "Stan may be honest" : "Stan is dishonest") << '\n';
      lo = 1;
      hi = 10;
    }
  }
}
