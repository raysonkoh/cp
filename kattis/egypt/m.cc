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

bool f(int x, int y, int z) { return (x * x) == (y * y + z * z); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x, y, z;
  while (cin >> x >> y >> z) {
    if (x == 0 && y == 0 && z == 0)
      break;

    if (f(x, y, z) || f(y, x, z) || f(z, x, y)) {
      cout << "right\n";
    } else {
      cout << "wrong\n";
    }
  }
}
