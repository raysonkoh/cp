#include <iostream>
#include <map>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    map<string, int> m;
    int res = 0;
    for (int j = 0; j < n; j++) {
      string s;
      cin >> s;
      if (m.find(s) == m.end()) {
        m[s] = 1;
        res++;
      }
    }
    cout << res << endl;
  }
  return 0;
}