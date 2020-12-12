#include <iostream>

using namespace std;

int main() {
  int l, x;
  cin >> l >> x;
  int curr = 0;
  int res = 0;
  for (int i = 0; i < x; i++) {
    string s;
    int p;
    cin >> s >> p;
    if (s == "enter") {
      if (curr + p > l) {
        res++;
      } else {
        curr += p;
      }
    } else {
      // exit
      curr -= p;
    }
  }
  cout << res << endl;
  return 0;
}
