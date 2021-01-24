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
  int x;
  cin >> x;
  string s;
  cin >> s;
  int diff = 0; // M - add, W - minus
  for (int i = 0; i < s.length() - 1; i++) {
    if (abs(diff) > x) {
      cout << i - 1 << '\n';
      return 0;
    }

    char c = s.at(i);
    char c2 = s.at(i + 1);

    int diffIfAdmitFirst = diff + (c == 'M' ? 1 : -1);
    int diffIfAdmitSecond = diff + (c2 == 'M' ? 1 : -1);
    if (abs(diffIfAdmitFirst) < abs(diffIfAdmitSecond)) {
      diff = diffIfAdmitFirst;
      // cout << "admit " << c << " diff: " << diff << endl;
    } else {
      swap(s[i], s[i + 1]);
      diff = diffIfAdmitSecond;
      // cout << "admit " << c2 << " diff: " << diff << endl;
    }
  }
  diff += (s.at(s.length() - 1) == 'M' ? 1 : -1);
  if (diff > x) {
    cout << s.length() - 1 << '\n';
  } else {
    cout << s.length() << '\n';
  }
}
