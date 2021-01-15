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
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    int l = lcm(s.length(), t.length());
    int sd = l / s.length();
    int td = l / t.length();
    string sres = "";
    string tres = "";
    for (int i = 0; i < sd; i++)
      sres += s;
    for (int i = 0; i < td; i++)
      tres += t;

    if (sres == tres)
      cout << sres;
    else
      cout << -1;
    cout << '\n';
  }
}