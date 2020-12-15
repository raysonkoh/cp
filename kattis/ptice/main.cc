#include <iostream>

using namespace std;

char getachar(int i) {
  i = i % 3;
  if (i == 0) {
    return 'A';
  } else if (i == 1) {
    return 'B';
  } else {
    return 'C';
  }
}

char getbchar(int i) {
  i = i % 4;
  if (i == 0 || i == 2) {
    return 'B';
  } else if (i == 1) {
    return 'A';
  } else {
    return 'C';
  }
}

char getcchar(int i) {
  i = i % 6;
  if (i == 0 || i == 1) {
    return 'C';
  } else if (i == 2 || i == 3) {
    return 'A';
  } else {
    return 'B';
  }
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  int c = 0;

  for (int i = 0; i < n; i++) {
    char ch = s.at(i);
    if (ch == getachar(i)) {
      a++;
    }

    if (ch == getbchar(i)) {
      b++;
    }

    if (ch == getcchar(i)) {
      c++;
    }
  }

  int maxnum = max(a, max(b, c));
  cout << maxnum << endl;
  if (a == maxnum) {
    cout << "Adrian " << endl;
  }
  if (b == maxnum) {
    cout << "Bruno" << endl;
  }
  if (c == maxnum) {
    cout << "Goran" << endl;
  }
}
