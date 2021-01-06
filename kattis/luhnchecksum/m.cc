#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> v(s.length());
    for (int i = 0; i < s.length(); i++) {
      v[i] = s.at(i) - '0';
    }

    for (int i = v.size() - 2; i >= 0; i -= 2) {
      int tmp = v[i] * 2;
      if (tmp >= 10) {
        tmp = (tmp % 10) + (tmp / 10);
      }
      v[i] = tmp;
    }
    int tol = 0;
    for (int x : v) {
      tol += x;
    }
    cout << (tol % 10 == 0 ? "PASS" : "FAIL") << "\n";
  }
}