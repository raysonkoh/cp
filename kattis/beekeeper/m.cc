#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define P 1e9 + 7
#define EPS 1e-11

using namespace std;

static vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};

bool isVowel(char c) {
  for (auto v : vowels) {
    if (c == v)
      return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> count(n, 0);
    int currMaxCount = -1;
    string maxS = "";
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.length() - 1; j++) {
        if (isVowel(s.at(j)) && s.at(j) == s.at(j + 1)) {
          count[i]++;
        }
      }

      if (currMaxCount < count[i]) {
        currMaxCount = count[i];
        maxS = s;
      }
    }
    cout << maxS << '\n';
  }
}
