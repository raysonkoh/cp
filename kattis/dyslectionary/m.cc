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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  vector<string> v;
  while (getline(cin, s)) {
    if (s == "") {
      sort(v.begin(), v.end());
      int maxLen = 0;
      for (string x : v)
        maxLen = max(maxLen, (int)x.length());
      for (string x : v) {
        string tmp = x;
        reverse(tmp.begin(), tmp.end());
        while (tmp.size() < maxLen)
          tmp = " " + tmp;
        cout << tmp << '\n';
      }
      cout << '\n';
      v.clear();
      continue;
    }

    reverse(s.begin(), s.end());
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  int maxLen = 0;
  for (string x : v)
    maxLen = max(maxLen, (int)x.length());
  for (string x : v) {
    string tmp = x;
    reverse(tmp.begin(), tmp.end());
    while (tmp.size() < maxLen)
      tmp = " " + tmp;
    cout << tmp << '\n';
  }
}
