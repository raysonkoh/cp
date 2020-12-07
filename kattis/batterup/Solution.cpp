#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int nume = 0;
  int denom = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == -1) {
      continue;
    }
    denom++;
    nume += x;
  }
  cout << fixed << setprecision(8) << ((double)nume) / ((double)denom) << endl;
  return 0;
}