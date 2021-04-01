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
qwertyuiop
asdfghjkl
zxcvbnm
*/

int getx(char c) {
  switch (c) {
    case 'q':
    case 'a':
    case 'z':
      return 1;
    case 'w':
    case 's':
    case 'x':
      return 2;
    case 'e':
    case 'd':
    case 'c':
      return 3;
    case 'r':
    case 'f':
    case 'v':
      return 4;
    case 't':
    case 'g':
    case 'b':
      return 5;
    case 'y':
    case 'h':
    case 'n':
      return 6;
    case 'u':
    case 'j':
    case 'm':
      return 7;
    case 'i':
    case 'k':
      return 8;
    case 'o':
    case 'l':
      return 9;
    case 'p':
      return 10;
  }
}

int gety(char c) {
  switch (c) {
    case 'q':
    case 'w':
    case 'e':
    case 'r':
    case 't':
    case 'y':
    case 'u':
    case 'i':
    case 'o':
    case 'p':
      return 1;
    case 'a':
    case 's':
    case 'd':
    case 'f':
    case 'g':
    case 'h':
    case 'j':
    case 'k':
    case 'l':
      return 2;
    case 'z':
    case 'x':
    case 'c':
    case 'v':
    case 'b':
    case 'n':
    case 'm':
      return 3;
  }
}

long long calcDist(string s, string s2) {
  long long res = 0;
  for (int i = 0; i < s.length(); i++) {
    int sx = getx(s.at(i));
    int sy = gety(s.at(i));
    int s2x = getx(s2.at(i));
    int s2y = gety(s2.at(i));
    res += abs(sx - s2x) + abs(sy - s2y);
  }
  return res;
}

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
    string s;
    int n;
    cin >> s >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<pair<long long, string>> vv(n);
    for (int i = 0; i < n; i++) {
      vv[i] = {calcDist(s, v[i]), v[i]};
    }
    sort(vv.begin(), vv.end(), [](pair<long long, string> p1, pair<long long, string> p2) {
      if (p1.first != p2.first) return p1.first < p2.first;
      return p1.second < p2.second;
    });
    for (auto [d, sss] : vv) {
      cout << sss << " " << d << '\n';
    }
  }
}
