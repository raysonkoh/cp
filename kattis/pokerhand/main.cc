#include <iostream>

using namespace std;

// A23456789TJQK
int getIndx(char c) {
  switch (c) {
  case 'A':
    return 0;
  case '2':
    return 1;
  case '3':
    return 2;
  case '4':
    return 3;
  case '5':
    return 4;
  case '6':
    return 5;
  case '7':
    return 6;
  case '8':
    return 7;
  case '9':
    return 8;
  case 'T':
    return 9;
  case 'J':
    return 10;
  case 'Q':
    return 11;
  case 'K':
    return 12;
  }
}

int main() {
  int arr[13];
  for (int i = 0; i < 13; i++) {
    arr[i] = 0;
  }

  for (int i = 0; i < 5; i++) {
    string s;
    cin >> s;
    int indx = getIndx(s.at(0));
    arr[indx]++;
  }

  int res = -1;
  for (int i = 0; i < 13; i++) {
    res = max(res, arr[i]);
  }
  cout << res << endl;
}
