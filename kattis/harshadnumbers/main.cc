#include <iostream>

using namespace std;

bool isHarshad(int x) {
  int sumOfDigits = 0;
  int tmp = x;
  while (tmp > 0) {
    sumOfDigits += tmp % 10;
    tmp = tmp / 10;
  }
  return x % sumOfDigits == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (true) {
    if (isHarshad(n)) {
      cout << n << endl;
      return 0;
    }
    n++;
  }
}