#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;

    int pw = p % 10;
    int num = p / 10;
    res += pow(num, pw);
  }
  cout << res << endl;
  return 0;
}