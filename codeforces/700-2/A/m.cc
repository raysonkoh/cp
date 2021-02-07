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
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      int ascii = (int)s.at(i);
      if (i % 2 == 0) {
        // alice
        for (int j = 97; j <= 122; j++) {
          if (j != ascii) {
            cout << (char)(j);
            break;
          }
        }
      } else {
        // bob
        for (int j = 122; j >= 97; j--) {
          if (j != ascii) {
            cout << (char)(j);
            break;
          }
        }
      }
    }
    cout << '\n';
  }
}
