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

int encode(string s) {
  if (s == "rock") {
    return 0;
  } else if (s == "scissors") {
    return 1;
  } else {
    return 2;
  }
}

// 1 - win, 0 - lose, -1 - draw
int detRes(int a, int b) {
  switch (a) {
  case 0: {
    switch (b) {
    case 0:
      return -1;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return 0;
      break;
    }
  }
  case 1: {
    switch (b) {
    case 0:
      return 0;
      break;
    case 1:
      return -1;
      break;
    case 2:
      return 1;
      break;
    }
  }
  case 2: {
    switch (b) {
    case 0:
      return 1;
      break;
    case 1:
      return 0;
      break;
    case 2:
      return -1;
      break;
    }
  }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  bool isFirst = true;
  while (1) {
    int n;
    cin >> n;
    if (n == 0)
      break;

    if (isFirst)
      isFirst = false;
    else
      cout << '\n';
    vector<int> loseGames(n, 0);
    vector<int> winGames(n, 0);
    int k;
    cin >> k;
    int numGames = k * n * (n - 1) / 2;
    for (int i = 0; i < numGames; i++) {
      int p1, p2;
      string s1, s2;
      cin >> p1 >> s1 >> p2 >> s2;
      int res = detRes(encode(s1), encode(s2));
      switch (res) {
      case -1:
        break;
      case 0:
        winGames[p2 - 1]++;
        loseGames[p1 - 1]++;
        break;
      case 1:
        winGames[p1 - 1]++;
        loseGames[p2 - 1]++;
        break;
      }
    }

    for (int i = 0; i < n; i++) {
      double a = winGames[i];
      double b = a + loseGames[i];
      if (b == 0) {
        cout << '-' << '\n';
      } else {
        double res = a / b;
        if ((int)(res * 10000.0) % 10 >= 5) {
          res = (int)(res * 1000.0) + 1;
          res /= 1000.0;
        }

        cout << fixed << setprecision(3) << res << '\n';
      }
    }
  }
}