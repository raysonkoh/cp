#include <iostream>

using namespace std;

int main() {
  string m;
  int d;
  cin >> m >> d;
  if ((m == "OCT" && d == 31) || (m == "DEC" && d == 25)) {
    cout << "yup" << endl;
  } else {
    cout << "nope" << endl;
  }
  return 0;
}