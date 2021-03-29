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
  int t;
  cin >> t;
  while (t--) {
    int n, w;
    cin >> n >> w;
    int biggestExp = log2(w);

    vector<int> v(biggestExp + 1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v[log2(x)]++;
    }

    vector<int> map(biggestExp + 1, 1);
    for (int i = 1; i < map.size(); i++) {
      map[i] = map[i - 1] * 2;
    }

    long long res = 0;
    while (n) {
      int tmpW = w;
      int currIndx = biggestExp;

      for (; currIndx >= 0 && n > 0; currIndx--) {
        if (v[currIndx] && tmpW >= map[currIndx]) {
          int numCan = min(tmpW / map[currIndx], v[currIndx]);
          // cout << "numCan: " << numCan << endl;
          tmpW -= numCan * map[currIndx];
          v[currIndx] -= numCan;
          n -= numCan;
        }
      }
      res++;
    }
    cout << res << '\n';
  }
}
