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
  getline(cin, s);
  int n = s.length() / 3;
  set<string> se;
  for (int i = 0; i < 3; i++) {
    string tmp = s.substr(i * n, n);
    if (se.count(tmp) == 0)
      se.insert(tmp);
    else {
      cout << tmp << '\n';
      return 0;
    }
  }
}
