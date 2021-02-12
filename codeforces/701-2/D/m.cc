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
  /*
  int l = 1;
  for (int i = 1; i <= 16; i++) {
    l = lcm(l, i);
  }
  cout << l << endl;
  */
  int n, m, tmp;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j];

  int def = 720720;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        tmp = def - pow(v[i][j], 4);
      } else {
        tmp = def;
      }
      cout << tmp << " ";
    }
    cout << '\n';
  }
}
