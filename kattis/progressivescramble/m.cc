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
  string s;
  getline(cin, s);
  while (n--) {
    getline(cin, s);
    char cmd = s.at(0);
    s = s.substr(2, s.length() - 2);
    if (cmd == 'd') {
      // decode
      vector<int> v(s.length());
      int curr = 0;
      for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == ' ') {
          v[i] = 0;
        } else {
          v[i] = s.at(i) - 'a' + 1;
        }
        if (i > 0) {
          v[i] -= curr;
        }
        curr += v[i];
      }
      for (int x : v) {
        int tmp = x;
        while (tmp < 0)
          tmp += 27;
        if (tmp == 0)
          cout << " ";
        else
          cout << (char)(tmp + 'a' - 1);
      }
      cout << '\n';
    } else {
      // encode
      vector<int> v(s.length());
      for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == ' ') {
          v[i] = 0;
        } else {
          v[i] = s.at(i) - 'a' + 1;
        }
        if (i > 0) {
          v[i] += v[i - 1];
        }
        v[i] = v[i] % 27;
      }
      for (int x : v) {
        if (x == 0)
          cout << " ";
        else
          cout << (char)(x + 'a' - 1);
      }
      cout << '\n';
    }
  }
}
