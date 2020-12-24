#include <iostream>

using namespace std;

bool check(int s, int a, int b) {
  if (s % (a + b) != 0) {
    return (s + b) % (a + b) == 0;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int s;
  cin >> s;
  int curr = 2;
  cout << s << ":" << endl;
  while (curr <= (s / 2) + 1) {
    if (check(s, curr, curr - 1)) {
      cout << curr << "," << curr - 1 << endl;
    }
    if (check(s, curr, curr)) {
      cout << curr << "," << curr << endl;
    }
    curr++;
  }
}