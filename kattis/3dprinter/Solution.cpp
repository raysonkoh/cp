#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int numprinters = 1;
  int numdays = 0;
  while (numprinters < n) {
    numprinters = numprinters * 2;
    numdays++;
  }
  cout << numdays + 1 << endl;

  return 0;
}