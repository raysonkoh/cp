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
  int n, y;
  cin >> n >> y;
  set<int> s;
  for (int i = 0; i < y; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  for (int i = 0; i < n; i++) {
    if (s.count(i) == 0)
      cout << i << '\n';
  }
  cout << "Mario got " << s.size() << " of the dangerous obstacles." << '\n';
}
