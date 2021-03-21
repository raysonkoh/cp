#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
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
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  getline(cin, s);
  int lineNum = 1;
  while (s != "END") {
    int prevBlack = -1;
    int diff = -1;
    bool can = true;
    for (int i = 0; i < s.length(); i++) {
      char c = s.at(i);
      if (c == '*') {
        if (prevBlack == -1) {
        } else {
          int tmpDiff = i - prevBlack + 1;
          if (diff != -1 && tmpDiff != diff) {
            can = false;
            break;
          } else {
            diff = tmpDiff;
          }
        }
        prevBlack = i;
      }
    }

    cout << lineNum << " " << (can ? "EVEN" : "NOT EVEN") << '\n';
    lineNum++;
    getline(cin, s);
  }
}
