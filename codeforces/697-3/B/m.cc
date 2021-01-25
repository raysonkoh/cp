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
  queue<int> q;
  set<int> s;
  s.insert(2020);
  s.insert(2021);
  q.push(2020);
  q.push(2021);
  while (q.size() > 0) {
    int fr = q.front();
    q.pop();
    if (fr + 2020 <= 1e6 && s.count(fr + 2020) == 0) {
      s.insert(fr + 2020);
      q.push(fr + 2020);
    }
    if (fr + 2021 <= 1e6 && s.count(fr + 2021) == 0) {
      s.insert(fr + 2021);
      q.push(fr + 2021);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (s.count(n) > 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}