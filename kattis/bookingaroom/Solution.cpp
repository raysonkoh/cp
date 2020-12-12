#include <iostream>
#include <set>

using namespace std;

int main() {
  int r, n;
  cin >> r >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  for (int i = 1; i <= r; i++) {
    if (s.find(i) == s.end()) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "too late" << endl;
  return 0;
}