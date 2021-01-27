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

bool existsZero(string s) { return s.find('0') != s.npos; }

bool allUnqiue(string s) {
  set<char> se;
  for (char c : s) {
    if (se.count(c) == 0)
      se.insert(c);
    else
      return false;
  }
  return true;
}

bool checkDivisible(int x, string s) {
  for (char c : s) {
    int ch = c - '0';
    if (x % ch == 0) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int l, h;
  cin >> l >> h;
  int res = 0;
  for (int i = l; i <= h; i++) {
    string s = to_string(i);
    if (!existsZero(s) && allUnqiue(s) && checkDivisible(i, s)) {
      res++;
    }
  }
  cout << res << '\n';
}
