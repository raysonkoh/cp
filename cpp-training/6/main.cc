#include <iostream>

using namespace std;

template <class T, class U> T smaller(T first, U second) {
  return first < second ? first : second;
}

int main() {
  int x = 10;
  double y = 5.674;
  cout << smaller(y, x) << endl;
}
