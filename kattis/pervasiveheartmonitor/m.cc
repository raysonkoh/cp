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

pair<string, int> getNextWord(string s, int st) {
  string res = "";
  for (int i = st; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ' ') {
      return make_pair(res, i);
    }
    res.push_back(c);
  }
  return make_pair(res, s.length());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string name = "";
  vector<string> v;
  string s;
  while (getline(cin, s)) {
    int i = 0;
    double tol = 0;
    int n = 0;
    while (i < s.length()) {
      auto [word, tmp] = getNextWord(s, i);
      i = tmp + 1;
      v.push_back(word);
    }

    for (string x : v) {
      if (isalpha(x.at(0))) {
        if (name == "")
          name = x;
        else
          name += " " + x;
      } else {
        tol += stod(x);
        n++;
      }
    }
    cout << fixed << setprecision(6) << tol / n << " " << name << '\n';
    name = "";
    v.clear();
  }
}
