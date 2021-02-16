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

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    pos[v[i] - 1] = i;
  }
  int lo = 0;
  int hi = n - 1;
  for (int phase = 1; phase <= n; phase++) {
    int numSwaps;
    if (phase % 2 == 1) {
      // choose smallest
      int posLo = pos[lo];
      numSwaps = posLo - lo;
      cout << "posLo: " << posLo << " numSwaps: " << numSwaps << '\n';
      lo++;
    } else {
      // choose largest
      int posHi = pos[hi];
      numSwaps = hi - posHi;
      cout << "posHi: " << posHi << " numSwaps: " << numSwaps << '\n';
      hi--;
    }

    cout << numSwaps << '\n';
  }
}
