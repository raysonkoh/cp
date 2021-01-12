#include <algorithm>
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
  int m, n;
  while (cin >> m >> n) {
    if (m == 0 && n == 0)
      break;

    int r = 0;
    int c = 0;
    int currR = 0;
    int currC = 0;

    int k;
    cin >> k;
    while (k--) {
      char ch;
      int x;
      cin >> ch >> x;
      switch (ch) {
      case 'u':
        r += x;
        currR = min(currR + x, n - 1);
        break;
      case 'd':
        r -= x;
        currR = max(currR - x, 0);
        break;
      case 'r':
        c += x;
        currC = min(currC + x, m - 1);
        break;
      case 'l':
        c -= x;
        currC = max(currC - x, 0);
        break;
      }
    }
    cout << "Robot thinks " << c << " " << r << '\n';
    cout << "Actually at " << currC << " " << currR << '\n';
    cout << '\n';
  }
}