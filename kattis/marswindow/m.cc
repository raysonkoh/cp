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
  int x;
  cin >> x;
  int mthDiff = (x - 2018) * 12;
  for (int i = -3; i <= 8; i++) {
    if ((mthDiff + i) % 26 == 0) {
      cout << "yes\n";
      return 0;
    }
  }
  cout << "no\n";
}
