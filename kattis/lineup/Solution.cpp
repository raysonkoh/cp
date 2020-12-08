#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  string first, second;
  cin >> first >> second;
  bool isIncr = true;
  bool isNei = false;
  if (first > second) {
    isIncr = false;
  } else {
    isIncr = true;
  }

  for (int i = 0; i < n - 2; i++) {
    string s;
    cin >> s;
    first = second;
    second = s;
    if ((isIncr && first > second) || (!isIncr && first < second)) {
      isNei = true;
      break;
    }
  }
  if (isNei) {
    cout << "NEITHER" << endl;
  } else if (isIncr) {
    cout << "INCREASING" << endl;
  } else {
    cout << "DECREASING" << endl;
  }
  return 0;
}