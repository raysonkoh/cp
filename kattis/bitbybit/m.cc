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
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> v(32, -1); // v[0] is LSB, v[31] is MSB
    while (n--) {
      string cmd;
      cin >> cmd;
      if (cmd == "CLEAR") {
        int i;
        cin >> i;
        v[i] = 0;
      } else if (cmd == "SET") {
        int i;
        cin >> i;
        v[i] = 1;
      } else if (cmd == "OR") {
        int i, j;
        cin >> i >> j;
        if (v[i] == 1 || v[j] == 1) {
          v[i] = 1;
        } else if (v[i] == -1 || v[j] == -1) {
          v[i] = -1;
        } else {
          v[i] = 0;
        }
      } else if (cmd == "AND") {
        int i, j;
        cin >> i >> j;
        if (v[i] == 0 || v[j] == 0) {
          v[i] = 0;
        } else if (v[i] == -1 || v[j] == -1) {
          v[i] = -1;
        } else {
          v[i] = 1;
        }
      }
    }

    for (int i = v.size() - 1; i >= 0; i--) {
      if (v[i] == -1) {
        cout << "?";
      } else {
        cout << v[i];
      }
    }
    cout << '\n';
  }
}
