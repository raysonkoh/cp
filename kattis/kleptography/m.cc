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
  int n, m;
  cin >> n >> m;
  vector<int> key(n);
  string p;
  cin >> p;
  string cipher;
  cin >> cipher;

  vector<char> plain(m);
  int sz = n - 1;
  for (int i = m - 1; sz >= 0; i--, sz--) {
    plain[i] = p.at(sz) - 'a';
  }

  for (int i = m - n - 1; i >= 0; i--) {
    plain[i] = (cipher.at(i + n) - 'a') - plain[i + n];
    plain[i] %= 26;
    if (plain[i] < 0)
      plain[i] += 26;
  }

  for (int x : plain) {
    cout << (char)(x + 'a');
  }
  cout << '\n';
}
