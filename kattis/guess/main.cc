#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int lo = 1;
  int hi = 1000;
  while (lo <= hi) {
    int mid = lo + ((hi - lo) / 2);
    cout << mid << endl;
    string res;
    cin >> res;
    if (res == "lower") {
      hi = mid - 1;
    } else if (res == "higher") {
      lo = mid + 1;
    } else {
      // correct
      break;
    }
  }
}