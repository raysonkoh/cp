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
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    string tmp = "";
    for (char c : s) {
      tmp.push_back(tolower(c));
    }
    if (tmp.find("pink") != tmp.npos || tmp.find("rose") != tmp.npos) {
      res++;
    }
  }
  cout << (res == 0 ? "I must watch Star Wars with my daughter" : to_string(res)) << '\n';
}
