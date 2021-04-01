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
  vector<int> exp(9);
  exp[0] = 1;
  for (int i = 1; i < exp.size(); i++) exp[i] = exp[i - 1] * 2;
  int t;
  cin >> t;
  while (t--) {
    int icode = 0;  // T - Black, F - white
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        char c;
        cin >> c;
        icode += (c == '*') * exp[i * 3 + j];
      }
    }

    queue<pair<int, long long>> q;
    set<int> seen;
    q.push({0, 0});
    seen.insert(0);
    if (icode == 0) {
      cout << 0 << '\n';
      continue;
    }
    long long res = -1;

    while (q.size() > 0) {
      auto [fr, num] = q.front();
      q.pop();
      bool found = false;
      for (int i = 0; i < 9; i++) {
        // flip at pos i affects: i, i - 1, i + 1, i - 3, i + 3
        int tmp = fr;
        // cout << "tmp before: " << tmp << " exp[i]: " << exp[i] << endl;
        tmp = tmp ^ exp[i];
        // cout << "after toggle first: " << tmp << endl;
        if (i - 1 >= 0 && i != 6 && i != 3 && i != 0) tmp = tmp ^ exp[i - 1];
        if (i + 1 < 9 && i != 8 && i != 5 && i != 2) tmp = tmp ^ exp[i + 1];
        if (i - 3 >= 0) tmp = tmp ^ exp[i - 3];
        if (i + 3 < 9) tmp = tmp ^ exp[i + 3];

        // cout << "flip at pos i: " << i << " tmp: " << tmp << endl;

        if (seen.count(tmp) == 0) {
          if (tmp == icode) {
            found = true;
            res = num + 1;
            break;
          }
          seen.insert(tmp);
          q.push({tmp, num + 1});
        }
      }
      if (found) break;
    }
    cout << res << '\n';
  }
}
