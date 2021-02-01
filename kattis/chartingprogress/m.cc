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

void printVect(vector<vector<int>> &v, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (v[j][i] ? '*' : '.');
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  vector<vector<int>> v;
  bool first = true;
  while (getline(cin, s)) {
    if (s == "") {
      if (first)
        first = false;
      else
        cout << '\n';
      int n = v.size();
      int m = v[0].size();
      vector<vector<int>> trf(m, vector<int>(n));
      for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
          trf[j][i] = v[i][j];
        }
      }
      sort(trf.begin(), trf.end());
      printVect(trf, n, m);
      v.clear();
    } else {
      vector<int> tmp;
      for (char c : s) {
        tmp.push_back(c == '*');
      }
      v.push_back(tmp);
    }
  }
  int n = v.size();
  if (n > 0) {
    if (first)
      first = false;
    else
      cout << '\n';
    int m = v[0].size();
    vector<vector<int>> trf(m, vector<int>(n));
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        trf[j][i] = v[i][j];
      }
    }
    sort(trf.begin(), trf.end());
    printVect(trf, n, m);
  }
}
