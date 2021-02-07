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
  int n;
  cin >> n;
  vector<int> v(n);
  vector<deque<int>> nxt(n + 1, deque<int>());
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    nxt[v[i]].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    nxt[v[i]].push_back(n + 1);
  }

  vector<int> v1;
  v1.push_back(0);
  vector<int> v2;
  v2.push_back(0);
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x = v[i];
    if (v1.back() == x) {
      if (v2.back() != x)
        res++;
      v2.push_back(x);
    } else if (v2.back() == x) {
      if (v1.back() != x)
        res++;
      v1.push_back(x);
    } else {
      if (nxt[v1.back()].size() == 0) {
        if (v2.back() != x)
          res++;
        v2.push_back(x);
      } else if (nxt[v2.back()].size() == 0) {
        if (v1.back() != x)
          res++;
        v1.push_back(x);
      } else if (nxt[v1.back()].front() < nxt[v2.back()].front()) {
        v1.push_back(x);
        res++;
      } else {
        v2.push_back(x);
        res++;
      }
    }

    nxt[v[i]].pop_front();
  }

  cout << res << '\n';
}
