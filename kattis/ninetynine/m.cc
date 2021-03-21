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

bool oppoCanWin(int x) {
  return x + 2 <= 99;
}

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
  bool isFirst = true;
  while (1) {
    if (isFirst) {
      cout << 2 << endl;
      isFirst = false;
      continue;
    }

    int x;
    cin >> x;
    if (x == 99)
      return 0;
    if (abs(99 - x) <= 2) {
      cout << 99 << endl;
      return 0;
    } else {
      if (x % 3 == 0) {
        cout << x + 1 << endl;
      } else {
        cout << x + 3 - (x % 3) << endl;
      }
    }
  }
}
