#include <algorithm>
#include <cassert>
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
const double EPS = 1e-9;

using namespace std;

int dfs(vector<bool> &v) {
  int res = 13;
  int ct = 0;
  for (int i = 0; i < 11; i++) {
    if (v[i])
      ct++;
    if (v[i] && v[i + 1]) {
      // pair, can slide left/right
      vector<bool> copy(v);
      if (i - 1 >= 0 && !v[i - 1]) {  // slide left
        copy[i - 1] = true;
        copy[i] = false;
        copy[i + 1] = false;
        res = min(res, dfs(copy));
      }
      vector<bool> copy2(v);
      if (i + 2 < 12 && !v[i + 2]) {
        copy2[i + 2] = true;
        copy2[i + 1] = false;
        copy2[i] = false;
        res = min(res, dfs(copy2));
      }
    }
  }
  if (v[11])
    ct++;
  return min(res, ct);
}

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    vector<bool> v(12);
    string s;
    cin >> s;
    for (int i = 0; i < 12; i++) {
      v[i] = s.at(i) == 'o';
    }
    cout << dfs(v) << '\n';
  }
}
