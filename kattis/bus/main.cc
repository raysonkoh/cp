#include <iostream>

using namespace std;

int determineK(int k) {
  if (k == 1) {
    return 1;
  } else {
    return 2 * determineK(k - 1) + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    cout << determineK(k) << endl;
  }
}