#include <algorithm>
#include <cassert>
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
const double EPS = 1e-9;

using namespace std;

int parseTime(string s) {
  string tmp = "";
  int hr = 0;
  int mi = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s.at(i) == ':') {
      hr += stoi(tmp);
      tmp = "";
      continue;
    } else if (s.at(i) == ' ') {
      mi += stoi(tmp);
      tmp = "";
      continue;
    }
    tmp.push_back(s.at(i));
  }
  hr %= 12;
  int res = hr * 60 + mi;
  if (tmp == "p.m.")
    res += 12 * 60;
  return res;
}

string convertTime(int t) {
  int hr = t / 60;
  int mi = t - hr * 60;
  bool isPm = false;
  if (hr >= 12) {
    hr -= 12;
    isPm = true;
  }
  if (hr == 0)
    hr = 12;
  string s = to_string(hr) + ":" + (mi < 10 ? "0" : "") + to_string(mi) + " " + (isPm ? "p.m." : "a.m.");
  return s;
}

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  bool isFirst = true;
  while (cin >> n) {
    if (n == 0) break;
    if (isFirst)
      isFirst = false;
    else
      cout << '\n';
    string s;
    getline(cin, s);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      int time = parseTime(s);
      v[i] = time;
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
      cout << convertTime(x) << '\n';
    }
  }
}
