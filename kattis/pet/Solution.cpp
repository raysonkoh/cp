#include <iostream>
#include <vector>

using namespace std;

int main() {
  int currMax = -1;
  int pos = -1;

  for (int i = 0; i < 5; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      int tmp;
      cin >> tmp;
      sum += tmp;
    }
    if (sum > currMax) {
      currMax = sum;
      pos = i;
    }
  }
  cout << pos + 1 << " " << currMax << endl;
  return 0;
}