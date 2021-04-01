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
  int caseNum = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    int curr = 0;
    for (int i = 1; i <= n / 2; i++) {
      int oppo = n - i + 1;
      int oppoIndx = oppo - 1;
      int indx = i - 1;
      curr += v[indx] != v[oppoIndx];
    }

    cout << "Case #" << caseNum << ": " << abs(k - curr) << '\n';
    caseNum++;
  }
}