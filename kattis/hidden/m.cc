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
  string p, s;
  cin >> p >> s;
  int curr = 0;
  for (int i = 0; i < p.length(); i++) {
    char expect = p.at(i);
    bool pass = false;
    while (curr < s.length()) {
      char c = s.at(curr);
      if (c == expect) {
        pass = true;
        curr++;
        break;
      }

      for (int j = i + 1; j < p.length(); j++) {
        if (c == p.at(j)) {
          cout << "FAIL\n";
          return 0;
        }
      }
      curr++;
    }

    if (!pass) {
      cout << "FAIL\n";
      return 0;
    }
  }
  cout << "PASS\n";
}