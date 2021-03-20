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

char getReflect(char c) {
  switch (c) {
    case '0':
    case '1':
    case '8':
      return c;
    case '2':
      return '5';
    case '5':
      return '2';
    default:
      return ' ';
  }
}

bool isReflectedTimeValid(string hstr, string mstr, int h, int m) {
  // cout << "hstr : " << hstr << " mstr: " << mstr << endl;
  string htemp = "";
  int mul = 1;
  int hres = 0;
  for (char c : mstr) {
    char r = getReflect(c);
    if (r == ' ')
      return false;
    htemp = to_string(r) + htemp;
    hres += (r - '0') * mul;
    mul *= 10;
  }

  string mtemp = "";
  mul = 1;
  int mres = 0;
  for (char c : hstr) {
    char r = getReflect(c);
    if (r == ' ')
      return false;
    mtemp = to_string(r) + mtemp;
    mres += (r - '0') * mul;
    mul *= 10;
  }

  // cout << "isvalid: hres: " << hres << " mres: " << mres << endl;
  return hres < h && mres < m;
}

pair<string, string> extract(string s) {
  return {s.substr(0, 2), s.substr(3, 2)};
}

string toString(int h, int m) {
  string hstr = "";
  while (h > 0) {
    hstr = to_string(h % 10) + hstr;
    h /= 10;
  }

  string mstr = "";
  while (m > 0) {
    mstr = to_string(m % 10) + mstr;
    m /= 10;
  }

  while (hstr.length() < 2) {
    hstr = '0' + hstr;
  }
  while (mstr.length() < 2) {
    mstr = '0' + mstr;
  }

  return hstr + ":" + mstr;
}

string increment(string s, int h, int m) {
  auto [hstr, mstr] = extract(s);
  int hres = 0;
  int mul = 10;
  for (char c : hstr) {
    hres += (c - '0') * mul;
    mul /= 10;
  }

  int mres = 0;
  mul = 10;
  for (char c : mstr) {
    mres += (c - '0') * mul;
    mul /= 10;
  }

  if (mres + 1 < m) {
    mres++;
  } else {
    mres = 0;
    if (hres + 1 < h) {
      hres++;
    } else {
      hres = 0;
    }
  }

  return toString(hres, mres);
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
  int t;
  cin >> t;
  while (t--) {
    int maxx = 60 * 60;
    int h, m;
    cin >> h >> m;
    string s;
    cin >> s;
    auto [hstr, mstr] = extract(s);
    // cout << hstr << " " << mstr << endl;

    while (maxx > 0 && !isReflectedTimeValid(hstr, mstr, h, m)) {
      s = increment(s, h, m);
      // cout << "incremented : " << s << endl;
      // cout << s << endl;
      auto [a, b] = extract(s);
      hstr = a;
      mstr = b;
      maxx--;
    }

    cout << s << '\n';
  }
}