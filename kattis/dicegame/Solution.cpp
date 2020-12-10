#include <iostream>

using namespace std;

double calce() {
  int a1, b1, a2, b2;
  cin >> a1 >> b1 >> a2 >> b2;

  double e1 = 0;
  double e2 = 0;

  for (int i = a1; i <= b1; i++) {
    e1 += i;
  }

  for (int i = a2; i <= b2; i++) {
    e2 += i;
  }
  return (e1 / (double)(b1 - a1 + 1)) + (e2 / (double)(b2 - a2 + 1));
}

int main() {
  double first = calce();
  double second = calce();
  if (first > second) {
    cout << "Gunnar" << endl;
  } else if (first == second) {
    cout << "Tie" << endl;
  } else {
    cout << "Emma" << endl;
  }
  return 0;
}