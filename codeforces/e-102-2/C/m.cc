#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int x = n - k;
    for (int i = 1; i <= k - x - 1; i++) {
      cout << i << " ";
    }
    for (int i = k; i >= k - x; i--) {
      cout << i << " ";
    }
    cout << '\n';
  }
}