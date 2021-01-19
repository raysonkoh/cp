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
#define LSOne(S) ((S) & -(S))

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
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    vector<long long> tmp = v;
    int swapi;
    int swapj;
    bool can = true;
    for (int i = 0; i < n - 1; i++) {
      long long newVal = tmp[i + 1] - tmp[i];
      if (newVal < 0) {
        can = false;
        swapi = i + 1;
        swapj = i + 2;
        break;
      } else {
        tmp[i + 1] = newVal;
        tmp[i] = 0;
      }
    }

    if (can) {
      if (tmp[n - 1] > 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      cout << swapi << " " << swapj << endl;
      swap(v[swapi], v[swapj]);
      can = true;
      for (int i = 0; i < n - 1; i++) {
        long long newVal = v[i + 1] - v[i];
        if (newVal < 0) {
          can = false;
          break;
        } else {
          v[i + 1] = newVal;
          v[i] = 0;
        }
      }

      if (v[n - 1] > 0) {
        can = false;
      }

      cout << (can ? "YES" : "NO") << "\n";
    }
  }
}
