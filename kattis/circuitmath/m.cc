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
  vector<bool> v(n);
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    v[i] = (ch == 'T');
  }
  char ch;
  stack<bool> s;
  while (cin >> ch) {
    if (ch == '*') {
      bool a = s.top();
      s.pop();
      bool b = s.top();
      s.pop();
      s.push(a && b);
    } else if (ch == '+') {
      bool a = s.top();
      s.pop();
      bool b = s.top();
      s.pop();
      s.push(a || b);
    } else if (ch == '-') {
      bool a = s.top();
      s.pop();
      s.push(!a);
    } else {
      s.push(v[ch - 'A']);
    }
  }
  cout << (s.top() ? 'T' : 'F') << '\n';
}
