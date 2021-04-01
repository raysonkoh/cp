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

char convertHex(int x) {
  switch (x) {
    case 10:
      return 'A';
    case 11:
      return 'B';
    case 12:
      return 'C';
    case 13:
      return 'D';
    case 14:
      return 'E';
    case 15:
      return 'F';
    default:
      return x + '0';
  }
}

// s should be length 4 octal -> return length 3 hexadecimal
string convert(vector<bool> bits) {
  string res = "";
  vector<int> exp{1, 2, 4, 8};
  int lo = 11;
  int hi = 8;
  int k = 0;

  while (hi >= 0) {
    int tmp = 0;
    for (int i = lo; i >= hi; i--, k++) {
      if (bits[i]) tmp += exp[k];
    }
    char tmpc = convertHex(tmp);
    res = tmpc + res;
    lo -= 4;
    hi -= 4;
    k = 0;
  }

  return res;
}

void pr(vector<bool> &v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << '\n';
}

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
  vector<int> exp{1, 2, 4};
  string s;
  cin >> s;
  string res = "";
  for (int i = s.length() - 1; i >= 0; i -= 4) {
    int tmp = 0;
    vector<bool> bits(12, false);
    int curr = 11;
    while ((i - tmp) >= 0 && tmp < 4) {
      int x = s.at(i - tmp) - '0';
      for (int j = 0; j < 3; j++) {
        bits[curr] = x & exp[j];
        curr--;
      }
      tmp++;
    }
    // pr(bits);
    string tmps = convert(bits);
    res = tmps + res;
  }

  while (res.length() > 1 && res.at(0) == '0') res = res.substr(1);

  cout << res << '\n';
}
