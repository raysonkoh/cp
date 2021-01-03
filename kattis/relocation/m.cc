#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int c, d;
      cin >> c >> d;
      c--;
      v[c] = d;
    } else {
      // 2
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      if (v[a] > v[b]) {
        swap(a, b);
      }
      cout << v[b] - v[a] << "\n";
    }
  }
}
