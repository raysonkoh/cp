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

bool isVowel(char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'); }

string convert(string s) {
  char firstChar = s.at(0);
  if (isVowel(firstChar)) {
    return s + "yay";
  }

  int vowIndx = -1;
  for (int i = 1; i < s.length(); i++) {
    if (isVowel(s.at(i))) {
      vowIndx = i;
      break;
    }
  }

  string beforeVow = s.substr(0, vowIndx);
  string res = s.substr(vowIndx, s.length() - vowIndx) + beforeVow + "ay";
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string line;
  while (getline(cin, line)) {
    int i = 0;
    bool isFirst = true;
    while (i < line.length()) {
      if (isFirst)
        isFirst = false;
      else
        cout << ' ';
      pair<string, int> p = getNextWord(line, i);
      string word = p.first;
      cout << convert(word);
      i = p.second + 1;
    }
    cout << '\n';
  }
}