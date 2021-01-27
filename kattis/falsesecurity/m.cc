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

  vector<string> v = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.", // F
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..", // L
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.", // R
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-", // X
    "-.--",
    "--.."
  };

  auto getCode = [&](char c) -> string {
    if (c == '_') {
      return "..--";
    } else if (c == ',') {
      return ".-.-";
    } else if (c == '.') {
      return "---.";
    } else if (c == '?') {
      return "----";
    } else {
      return v[c - 'A'];
    }
  };
  string s;
  while (getline(cin, s)) {
    string res = "";
    vector<int> num;
    for (char c : s) {
      string code = getCode(c);
      res.append(code);
      num.push_back(code.length());
    }
    reverse(num.begin(), num.end());
    int curr = 0;
    string res2 = "";
    for (int x : num) {
      int i = curr;
      string tmp = "";
      for (; i < x + curr; i++) {
        tmp.push_back(res.at(i));
      }

      if (tmp == "..--") {
        res2.push_back('_');
      } else if (tmp == ".-.-") {
        res2.push_back(',');
      } else if (tmp == "---.") {
        res2.push_back('.');
      } else if (tmp == "----") {
        res2.push_back('?');
      } else {
        int indx = find(v.begin(), v.end(), tmp) - v.begin();
        res2.push_back((char)(indx + (int)'A'));
      }
      curr = i;
    }
    cout << res2 << endl;
  }
}
