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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int st = 0;
    int ed = n - 1;
    while (true) {
      if (st == ed) {
        cout << v[st] << "\n";
        break;
      } else if (st > ed) {
        cout << "\n";
        break;
      }
      cout << v[st] << " ";
      cout << v[ed] << " ";
      st++;
      ed--;
    }
  }
}