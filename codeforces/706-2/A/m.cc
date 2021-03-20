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
  while (t--) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    // cout << s << endl;

    string s1 = "";
    string s2 = "";
    int lo = 0;
    int hi = n - 1;
    for (int i = 0; i < k; i++) {
      s1 = "";
      s2 = "";
      s1.push_back(s.at(lo));
      s2.push_back(s.at(hi));
      lo++;
      hi--;
      // cout << s1 << " " << s2 << endl;
      while (s1 != s2 && lo <= hi) {
        s1.push_back(s.at(lo));
        s2.push_back(s.at(hi));
        lo++;
        hi--;
      }
      if (lo > hi) {
        break;
      }
    }

    if (lo > hi) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
