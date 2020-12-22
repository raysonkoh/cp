#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  char c1 = s.at(0);
  int r1 = 0;
  char c2 = c1;
  int r2 = 0;
  char c3 = c1;
  int r3 = 0;
  for (int i = 1; i < s.length(); i++) {
    char curr = s.at(i);
    // policy 1
    if (c1 != curr) {
      c1 = curr;
      r1++;
    }
    if (curr != 'U') {
      c1 = 'U';
      r1++;
    }
    // policy 2
    if (c2 != curr) {
      c2 = curr;
      r2++;
    }
    if (curr != 'D') {
      c2 = 'D';
      r2++;
    }
    // policy 3
    if (c3 != curr) {
      c3 = curr;
      r3++;
    }
  }
  cout << r1 << endl;
  cout << r2 << endl;
  cout << r3 << endl;
}