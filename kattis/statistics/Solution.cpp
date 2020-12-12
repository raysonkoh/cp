#include <iostream>

using namespace std;

int main() {
  int n;
  int casenum = 1;
  while (cin >> n) {
    int maxn = -1000001;
    int minn = 1000001;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      maxn = max(maxn, x);
      minn = min(minn, x);
    }
    cout << "Case " << casenum << ": " << minn << " " << maxn << " "
         << maxn - minn << endl;
    casenum++;
  }
  return 0;
}