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

int genhash(string s) {
  int res = 0;
  for (char c : s) {
    res = res ^ (toascii(c));
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
  int n;
  while (cin >> n) {
    if (n == 0) break;
    string s;
    getline(cin, s);
    vector<string> v(n);
    set<string> ss;
    map<int, vector<string>> m;
    long long col = 0;
    long long uniq = 0;
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      v[i] = s;
      int h = genhash(s);
      // cout << "s: " << s << " h: " << h << endl;
      if (ss.count(s) == 0) {
        uniq++;
        ss.insert(s);
      }
      if (m.count(h) == 0) m[h] = vector<string>();
      m[h].push_back(s);
    }

    for (auto [h, ve] : m) {
      for (int i = 0; i < ve.size(); i++) {
        for (int j = i + 1; j < ve.size(); j++) {
          if (ve[i] != ve[j]) col++;
        }
      }
    }

    cout << uniq << " " << col << '\n';
  }
}
