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

int getNumPeb(int x, vector<int> &exp) {
  int res = 0;
  for (int i = 0; i < exp.size(); i++) {
    if (x & exp[i]) res++;
  }
  return res;
}

void pr(int x, vector<int> &exp) {
  for (int i = 0; i < exp.size(); i++) {
    cout << (exp[i] & x ? 1 : 0) << " ";
  }
  cout << endl;
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
  vector<int> exp(23);
  exp[0] = 1;
  for (int i = 1; i < exp.size(); i++) {
    exp[i] = exp[i - 1] * 2;
  }
  int t;
  cin >> t;
  while (t--) {
    int curr = 0;
    int res = 0;
    for (int i = 0; i < 23; i++) {
      char c;
      cin >> c;
      curr += (c == 'o') * exp[i];
      if (c == 'o') res++;
    }
    queue<int> q;
    set<int> seen;
    q.push(curr);
    seen.insert(curr);
    while (q.size() > 0) {
      int fr = q.front();
      q.pop();
      // pr(fr, exp);

      for (int i = 0; i < exp.size(); i++) {
        if (i + 1 < exp.size() && (fr & exp[i]) && (fr & exp[i + 1])) {
          // remove ith, shift to i - 1
          if (i - 1 >= 0 && ((fr & exp[i - 1]) == 0)) {
            int tmp = fr;
            tmp = tmp ^ exp[i];      // remove ith
            tmp = tmp ^ exp[i + 1];  // remove (i + 1)th
            tmp = tmp ^ exp[i - 1];  // shift to (i - 1)th
            if (seen.count(tmp) == 0) {
              seen.insert(tmp);
              q.push(tmp);
              res = min(res, getNumPeb(tmp, exp));
            }
          }
          // remove (i + 1)th, shift to i + 2
          if (i + 2 < exp.size() && ((fr & exp[i + 2]) == 0)) {
            int tmp = fr;
            tmp = tmp ^ exp[i];      // remove ith
            tmp = tmp ^ exp[i + 1];  // remove (i + 1)th
            tmp = tmp ^ exp[i + 2];  // shift to (i + 2)th
            if (seen.count(tmp) == 0) {
              seen.insert(tmp);
              q.push(tmp);
              res = min(res, getNumPeb(tmp, exp));
            }
          }
        }
      }
    }
    cout << res << '\n';
  }
}
