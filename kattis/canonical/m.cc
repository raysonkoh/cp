#include <algorithm>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int maxSize = v[n - 1] + v[n - 2];

  vector<int> dp(maxSize + 1, maxSize + 2); // min number of ways to change coins
  for (int i = 0; i < dp.size(); i++) {
    if (i == 0) {
      dp[i] = 0;
    } else {
      for (int j = 0; j < n; j++) {
        if (i - v[j] >= 0)
          dp[i] = min(dp[i], dp[i - v[j]] + 1);
        else
          break;
      }
    }
  }

  vector<int> greedy(maxSize + 1, maxSize + 2);
  for (int i = 0; i < greedy.size(); i++) {
    if (i == 0) {
      greedy[i] = 0;
    } else {
      int choiceIndx = lower_bound(v.begin(), v.end(), i) - v.begin();

      if (choiceIndx == v.size())
        choiceIndx--;

      int choice = v[choiceIndx];
      if (choice > i)
        choice = v[choiceIndx - 1];

      greedy[i] = greedy[i - choice] + 1;
    }
  }

  for (int i = 0; i < dp.size(); i++) {
    if (dp[i] != greedy[i]) {
      cout << "non-canonical\n";
      return 0;
    }
  }
  cout << "canonical\n";
}