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

void combine(vector<bool> &v, vector<bool> &v1) {
  for (int i = 0; i < v.size(); i++) {
    v[i] = v[i] || v1[i];
  }
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
  int n;
  cin >> n;
  int e;
  cin >> e;
  vector<vector<bool>> v(n + 1, vector<bool>(e, false));
  for (int i = 0; i < e; i++) {
    int k;
    cin >> k;
    vector<int> tmp(k);
    bool hasOne = false;
    for (int ii = 0; ii < k; ii++) {
      int x;
      cin >> x;
      if (x == 1) hasOne = true;
      tmp[ii] = x;
    }
    if (hasOne) {
      for (auto x : tmp) v[x][i] = true;
    } else {
      vector<bool> combined(e, false);
      for (auto ve : v) {
        combine(combined, ve);
      }

      for (auto x : tmp) {
        vector<bool> cpy(combined);
        v[x] = cpy;
      }
    }
  }

  vector<bool> first = v[1];
  vector<int> res{1};
  for (int i = 2; i <= n; i++) {
    bool can = true;
    for (int j = 0; j < first.size(); j++) {
      if (first[j] != v[i][j]) {
        can = false;
        break;
      }
    }
    if (can) res.push_back(i);
  }

  for (auto x : res) {
    cout << x << '\n';
  }
}
