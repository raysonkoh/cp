#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int p, n;
  cin >> p >> n;
  set<string> seen;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (seen.find(s) == seen.end()) {
      p--;
      seen.insert(s);
      if (p == 0) {
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << "paradox avoided" << endl;
}