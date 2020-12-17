#include <climits>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int maxx = INT_MIN;
    int minx = INT_MAX;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      maxx = max(maxx, x);
      minx = min(minx, x);
    }
    cout << 2 * (maxx - minx) << endl;
  }
}