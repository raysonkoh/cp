#include <iostream>

using namespace std;

void update(int *a, int *b) {
  // Complete this function
  int newA, newB;
  newA = *a + *b;
  newB = abs(*a - *b);
  *a = newA;
  *b = newB;
}

int main() {
  int a, b;
  cin >> a >> b;
  update(&a, &b);
  cout << a << endl;
  cout << b << endl;
  return 0;
}