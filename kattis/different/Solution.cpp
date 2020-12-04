#include <iostream>
#include <string>

using namespace std;

long long findDiff(long long a, long long b) {
  if (a < b) {
    return findDiff(b, a);
  }
  return a - b;
}

int main() {
  long long a, b;
  while (cin >> a >> b) {
    cout << findDiff(a, b) << endl;
  }
  return 0;
}