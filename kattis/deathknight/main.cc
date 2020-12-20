#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    char prev = s.at(0);
    bool canCount = true;
    for (int i = 1; i < s.length(); i++) {
      char curr = s.at(i);
      if (prev == 'C' && curr == 'D') {
        canCount = false;
        break;
      }
      prev = curr;
    }
    if (canCount) {
      res++;
    }
  }
  cout << res << endl;
}