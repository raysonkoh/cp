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
  string word;
  getline(cin, word);
  map<char, int> cnt;
  for (char c : word) {
    if (cnt.count(c) == 0)
      cnt[c] = 0;
    cnt[c]++;
  }
  string perm;
  getline(cin, perm);
  int num = 0;
  bool can = false;
  int wrong = 0;
  for (char c : perm) {
    if (cnt.count(c) > 0) {
      num += cnt[c];
      if (num == word.length()) {
        can = true;
        break;
      }
    } else {
      wrong++;
      if (wrong == 10) {
        break;
      }
    }
  }
  cout << (can ? "WIN" : "LOSE") << '\n';
}
