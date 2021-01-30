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
  string y, p;
  cin >> y >> p;
  auto isvowel = [](char c) {
    return c == 'a' || c == 'i' || c == 'o' || c == 'u';
  };
  if (y.at(y.length() - 1) == 'e') {
    y = y.substr(0, y.length() - 1);
  } else if (isvowel(y.at(y.length() - 1))) {
    y = y.substr(0, y.length() - 1);
  } else if (y.substr(y.length() - 2, 2) == "ex") {
    y = y.substr(0, y.length() - 2);
  }
  cout << y + "ex" + p << '\n';
}
