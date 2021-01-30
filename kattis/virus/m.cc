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
  deque<char> orig;
  deque<char> after;
  string s;
  getline(cin, s);
  for (char c : s)
    orig.push_back(c);
  getline(cin, s);
  for (char c : s)
    after.push_back(c);

  while (orig.size() > 0 && after.size() > 0 && orig.front() == after.front()) {
    orig.pop_front();
    after.pop_front();
  }
  while (orig.size() > 0 && after.size() > 0 && orig.back() == after.back()) {
    orig.pop_back();
    after.pop_back();
  }

  int res = after.size();

  cout << res << '\n';
}
