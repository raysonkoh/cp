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
const double EPS = 1e-11;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  getline(cin, s);
  vector<int> dp(s.length(), 1);
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      dp[i] = 1;
      continue;
    }

    for (int j = i - 1; j >= 0; j--) {
      if (s.at(i) > s.at(j))
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  cout << 26 - *max_element(dp.begin(), dp.end()) << '\n';
}
