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
  int t;
  cin >> t;
  while (t--) {
    int n, m, l;
    cin >> n >> m >> l;
    vector<set<int>> adjList(n + 1, set<int>());
    while (m--) {
      int x, y;
      cin >> x >> y;
      adjList[x].insert(y);
    }
    set<int> seen;
    while (l--) {
      int x;
      cin >> x;
      if (seen.count(x) > 0)
        continue;
      seen.insert(x);
      queue<int> q;
      q.push(x);
      while (q.size() > 0) {
        int nd = q.front();
        q.pop();
        for (int nei : adjList[nd]) {
          if (seen.count(nei) > 0)
            continue;
          seen.insert(nei);
          q.push(nei);
        }
      }
    }
    cout << seen.size() << '\n';
  }
}
