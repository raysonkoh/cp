#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<bool> burst(n, false);
  vector<int> v(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
    v[i] = x;
  }
  int indx = 0;
  int res = 0;
  while (indx < n) {
    // shoot at v[indx]
    int currh = v[indx];
    burst[indx] = true;
    while (true) {
      if (s.find(currh - 1) != s.end()) {
      }
    }
  }
  cout << res << endl;
}