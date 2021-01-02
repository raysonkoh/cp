#include <iostream>
#include <set>

using namespace std;

bool verify(int x, int sum) {
  set<int> s;
  int check = 0;
  while (x > 0) {
    int a = x % 10;
    check += a;
    if (s.find(a) != s.end()) {
      return false;
    } else {
      s.insert(a);
    }
    x = x / 10;
  }
  return check == sum;
}

int solve(int x) {
  if (x > 45) {
    return -1;
  }
  int res = 0;
  int currMax = 9;
  int currDigit = 1;
  while (x >= 10) {
    // cout << "x: " << x << " res: " << res << endl;
    res = res + currMax * currDigit;
    x -= currMax;
    currMax--;
    currDigit *= 10;
    // cout << "after x: " << x << " res: " << res << endl;
  }

  if (x > currMax) {
    // used before
    while (x > 0) {
      if (x < currMax) {
        currMax--;
        continue;
      }
      res = res + currMax * currDigit;
      x -= currMax;
      currMax--;
      currDigit *= 10;
    }
  } else {
    res = res + x * currDigit;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  // t = 50;
  // int x = 50;
  while (t--) {
    int x;
    cin >> x;
    int res = solve(x);

    // cout << "x: " << x << endl;
    cout << res << "\n";
    // if (!verify(res, x)) {
    // cout << "WRONG for x: " << x << endl;
    //}
  }
}