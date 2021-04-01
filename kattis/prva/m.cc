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

  int r, c;
  cin >> r >> c;
  vector<vector<char>> v(r, vector<char>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }
  set<string> s;
  for (int i = 0; i < r; i++) {
    string st = "";
    for (int j = 0; j < c; j++) {
      if (v[i][j] == '#') {
        s.insert(st);
        st = "";
      } else {
        st.push_back(v[i][j]);
      }
    }
    if (st != "") s.insert(st);
  }

  for (int j = 0; j < c; j++) {
    string st = "";
    for (int i = 0; i < r; i++) {
      if (v[i][j] == '#') {
        s.insert(st);
        st = "";
      } else {
        st.push_back(v[i][j]);
      }
    }
    if (st != "") s.insert(st);
  }

  while (s.size() > 0 && (*s.begin()).length() < 2) {
    s.erase(s.begin());
  }

  cout << *s.begin() << '\n';
}
