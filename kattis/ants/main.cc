#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int l;
    int n;
    cin >> l >> n;
    int minTime = -1;
    int maxTime = -1;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      int toLeft = x;
      int toRight = l - x;
      minTime = max(minTime, min(toLeft, toRight));
      maxTime = max(maxTime, max(toLeft, toRight));
    }
    cout << minTime << " " << maxTime << "\n";
  }
}