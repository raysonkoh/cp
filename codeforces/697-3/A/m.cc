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
    long long n;
    cin >> n;
    if (n <= 2) {
      cout << "NO\n";
    } else {
      if (n % 2 == 1) {
        cout << "YES\n";
      } else {
        while (n % 2 == 0) {
          n /= 2;
        }
        if (n == 1) {
          cout << "NO\n";
        } else {
          cout << (n % 2 == 0 ? "NO\n" : "YES\n");
        }
      }
    }
  }
}
