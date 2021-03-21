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

pair<string, int> getNextWord(string s, int st) {
  string res = "";
  for (int i = st; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ';') {
      return make_pair(res, i);
    }
    res.push_back(c);
  }
  return make_pair(res, s.length());
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
  string s;
  getline(cin, s);
  vector<string> v;
  int i = 0;
  while (i < s.length()) {
    auto [wd, ii] = getNextWord(s, i);
    // cout << wd << endl;
    i = ii + 1;
    v.push_back(wd);
  }

  int res = 0;
  for (string wd : v) {
    if (wd.find('-') != wd.npos) {
      string f = wd.substr(0, wd.find('-'));
      string ss = wd.substr(wd.find('-') + 1, wd.length() - f.length() - 1);
      // cout << "f: " << f << " ss: " << ss << endl;
      res += stoi(ss) - stoi(f) + 1;
    } else {
      res++;
    }
  }
  cout << res << '\n';
}
