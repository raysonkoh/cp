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
    int n;
    cin >> n;
    queue<int> q; // contains indx
    for (int i = 0; i < n; i++) {
      q.push(i);
    }
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        int tmp = q.front();
        q.pop();
        q.push(tmp);
      }
      int indx = q.front();
      // cout << "indx: " << indx << " i: " << i << endl;
      v[indx] = i;
      q.pop();
    }
    bool isFirst = true;
    for (auto x : v) {
      if (isFirst)
        isFirst = false;
      else
        cout << " ";
      cout << x;
    }
    cout << '\n';
  }
}
