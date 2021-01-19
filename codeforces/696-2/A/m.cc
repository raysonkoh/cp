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
    string b;
    cin >> b;
    string a = "1";
    vector<int> res(n);
    res[0] = 1 + (b.at(0) == '1');
    for (int i = 1; i < b.size(); i++) {
      // always try to add 1
      int currDigit = b.at(i) - '0';
      if (currDigit + 1 == res.at(i - 1)) {
        a.push_back('0');
        res[i] = currDigit;
      } else {
        a.push_back('1');
        res[i] = currDigit + 1;
      }
    }
    cout << a << '\n';
  }
}
