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

pair<string, int> getNextWord(string s, int st) {
  string res = "";
  for (int i = st; i < s.length(); i++) {
    char c = s.at(i);
    if (c == ' ') {
      return make_pair(res, i);
    }
    res.push_back(c);
  }
  return make_pair(res, s.length());
}

int parseTime(string s) {
  string hr, min;
  int i = s.find(":");
  hr = s.substr(0, i);
  min = s.substr(i + 1, s.length() - hr.length() - 1);
  return stoi(hr) * 60 + stoi(min);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    int i = 0;
    int n = 0;
    string date = "";
    int t1, t2;
    while (i < s.length()) {
      auto [word, tmp] = getNextWord(s, i);
      i = tmp + 1;
      if (n < 3) {
        if (n == 0)
          date = word;
        else
          date += " " + word;
      } else if (n == 3) {
        t1 = parseTime(word);
      } else {
        t2 = parseTime(word);
      }
      n++;
    }

    int timeDiff = t2 - t1;
    if (timeDiff < 0)
      timeDiff += 24 * 60;
    int hr = 0, min = 0;
    while (timeDiff - 60 >= 0) {
      timeDiff -= 60;
      hr++;
    }
    while (timeDiff - 1 >= 0) {
      timeDiff -= 1;
      min++;
    }
    cout << date << " " << hr << " hours"
         << " " << min << " minutes" << '\n';
  }
}
