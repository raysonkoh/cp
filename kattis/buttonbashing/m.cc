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
  int k;
  cin >> k;
  while (k--) {
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    queue<int> q;
    vector<int> minNum(3600 + 1, 1e9);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    q.push(0);
    minNum[0] = 0;
    while (q.size() > 0) {
      int fr = q.front();
      int ct = minNum[fr];
      q.pop();
      for (int x : v) {
        int newVal = min(3600, max(0, fr + x));
        if (ct + 1 < minNum[newVal]) {
          minNum[newVal] = ct + 1;
          q.push(newVal);
        }
      }
    }

    for (int i = t; i < 3601; i++) {
      if (minNum[i] < 1e9) {
        cout << minNum[i] << " " << (i - t) << '\n';
        break;
      }
    }
  }
}