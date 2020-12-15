#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long minnum = 1000000001;
  int minindx = -1;
  for (int i = 0; i < n; i++) {
    long x;
    cin >> x;
    if (x < minnum) {
      minnum = x;
      minindx = i;
    }
  }
  cout << minindx << endl;
}
