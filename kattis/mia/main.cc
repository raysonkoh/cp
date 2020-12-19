#include <iostream>

using namespace std;

bool ishighest(int a, int b) {
  return (a == 1 && b == 2) || (a == 2 && b == 1);
}

bool comparehighest(int a, int b, int c, int d) {
  if (ishighest(a, b) && ishighest(c, d)) {
    cout << "Tie." << endl;
    return true;
  } else if (ishighest(a, b)) {
    cout << "Player 1 wins." << endl;
    return true;
  } else if (ishighest(c, d)) {
    cout << "Player 2 wins." << endl;
    return true;
  }
  return false;
}

bool isdouble(int a, int b) { return a == b; }

bool comparedouble(int a, int b, int c, int d) {
  if (isdouble(a, b) && isdouble(c, d)) {
    if (a == c) {
      cout << "Tie." << endl;
    } else if (a > c) {
      cout << "Player 1 wins." << endl;

    } else {
      cout << "Player 2 wins." << endl;
    }
    return true;
  } else if (isdouble(a, b)) {
    cout << "Player 1 wins." << endl;
    return true;
  } else if (isdouble(c, d)) {
    cout << "Player 2 wins." << endl;
    return true;
  }
  return false;
}

int getval(int a, int b) {
  if (a < b) {
    return getval(b, a);
  }
  return a * 10 + b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int s0, s1, r0, r1;
  while (cin >> s0 >> s1 >> r0 >> r1) {
    if (s0 == 0 && s1 == 0 && r0 == 0 && r1 == 0) {
      break;
    }
    if (comparehighest(s0, s1, r0, r1)) {
      continue;
    } else if (comparedouble(s0, s1, r0, r1)) {
      continue;
    } else {
      int aval = getval(s0, s1);
      int bval = getval(r0, r1);

      if (aval == bval) {
        cout << "Tie." << endl;
      } else if (aval > bval) {
        cout << "Player 1 wins." << endl;
      } else {
        cout << "Player 2 wins." << endl;
      }
    }
  }
}