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

bool simulate(vector<int> &v, int dx, int dy) {
  int x = 0;
  int y = 0;
  /*
    0 - UP
    1 - RIGHT
    2 - DOWN
    3 - LEFT
  */
  int dir = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 1) {
      // forward
      switch (dir) {
      case 0:
        y++;
        break;
      case 1:
        x++;
        break;
      case 2:
        y--;
        break;
      case 3:
        x--;
        break;
      }
    } else if (v[i] == 2) {
      // left
      dir--;
      if (dir < 0)
        dir += 4;
    } else if (v[i] == 3) {
      // right
      dir++;
      dir %= 4;
    }
  }

  return x == dx && y == dy;
}

void printAns(int i, int num) {
  cout << i + 1 << " ";
  switch (num) {
  case 1:
    cout << "Forward\n";
    break;
  case 2:
    cout << "Left\n";
    break;
  case 3:
    cout << "Right\n";
    break;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x, y;
  cin >> x >> y;
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "Forward") {
      v[i] = 1;
    } else if (s == "Left") {
      v[i] = 2;
    } else {
      v[i] = 3;
    }
  }

  for (int i = 0; i < n; i++) {
    int orig = v[i];
    if (v[i] == 1) {
      v[i] = 2;
      bool can = simulate(v, x, y);
      if (can) {
        printAns(i, v[i]);
        return 0;
      }
      v[i] = 3;
      can = simulate(v, x, y);
      if (can) {
        printAns(i, v[i]);
        return 0;
      }
    } else if (v[i] = 2) {
      v[i] = 1;
      bool can = simulate(v, x, y);
      if (can) {
        printAns(i, v[i]);
        return 0;
      }

      v[i] = 3;
      can = simulate(v, x, y);
      if (can) {
        printAns(i, v[i]);
        return 0;
      }
    } else if (v[i] = 3) {
      v[i] = 1;
      bool can = simulate(v, x, y);
      if (can) {
        printAns(i, v[i]);
        return 0;
      }
      v[i] = 2;
      can = simulate(v, x, y);
      if (can) {
        printAns(i, v[i]);
        return 0;
      }
    }
    v[i] = orig;
  }
}
