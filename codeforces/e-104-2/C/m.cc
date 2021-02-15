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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << 0 << '\n';
      continue;
    }

    int numGames = n * (n - 1) / 2;
    int winEach = numGames / n;
    int tolWins = winEach * n;
    int tolPts = 3 * tolWins + (numGames - tolWins) * 2;
    int ptEach = tolPts / n;

    vector<int> score(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (score[i] == ptEach) {
          if (ptEach - score[j] >= 3) {
            score[j] += 3;
            cout << -1 << " ";
          } else {
            score[j]++;
            score[i]++;
            cout << 0 << " ";
          }
        } else {
          if (ptEach - score[i] >= 3) {
            score[i] += 3;
            cout << 1 << " ";
          } else {
            score[i]++;
            score[j]++;
            cout << 0 << " ";
          }
        }
      }
    }
    cout << '\n';
  }
}
