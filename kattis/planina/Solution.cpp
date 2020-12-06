#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long ptsPerSide = 3;
  for (int i = 1; i < n; i++) {
    ptsPerSide = ptsPerSide * 2 - 1;
  }
  cout << (ptsPerSide * ptsPerSide) << endl;
  return 0;
}