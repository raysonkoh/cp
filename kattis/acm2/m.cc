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
  int n, p;
  cin >> n >> p;
  set<int> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
    v[i] = x;
  }
  long long res = 0;
  int num = 0;
  int currTime = 0;
  if (v[p] > 300) {
    cout << 0 << " " << 0 << '\n';
    return 0;
  }

  currTime += v[p];
  s.erase(v[p]);
  num++;
  res += v[p];
  while (true && s.size() > 0) {
    int nxt = *s.begin();
    if (currTime + nxt <= 300) {
      s.erase(nxt);
      currTime += nxt;
      num++;
      res += currTime;
    } else {
      break;
    }
  }
  cout << num << " " << res << '\n';
}
