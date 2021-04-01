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

pair<bool, int> isRed(int time, int r, int g) {
  int numIt = 0;
  while (time >= r + g) {
    time -= (r + g);
    numIt++;
  }
  return {time < r, numIt * (r + g) + r};
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
  int n, l;
  cin >> n >> l;
  int res = 0;
  int currd = 0;
  for (int i = 0; i < n; i++) {
    int d, r, g;
    cin >> d >> r >> g;
    res += d - currd;
    if (isRed(res, r, g).first) {
      // cout << "time: " << res << " is red\n";
      // cout << isRed(res, r, g).second << endl;
      res = isRed(res, r, g).second;
    }
    currd = d;
  }
  res += l - currd;
  cout << res << '\n';
}
