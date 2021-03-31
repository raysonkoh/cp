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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 2);
    for (int i = 0; i < n + 2; i++) {
      int x, y;
      cin >> x >> y;
      v[i] = {x, y};
    }

    queue<int> q;
    set<int> seen;
    seen.insert(0);
    q.push(0);
    while (q.size() > 0) {
      int x = q.front();
      q.pop();
      for (int i = 0; i < v.size(); i++) {
        if (i == x || seen.count(i) > 0) continue;

        if ((abs(v[x].first - v[i].first) + abs(v[x].second - v[i].second)) <= 1000) {
          seen.insert(i);
          q.push(i);
        }
      }
    }

    if (seen.count(n + 1) > 0) {
      cout << "happy\n";
    } else {
      cout << "sad\n";
    }
  }
}
