#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  string a_r = "", b_r = "";
  for (int i = a.length() - 1; i >= 0; i--) {
    a_r.push_back(a.at(i));
  }
  for (int i = b.length() - 1; i >= 0; i--) {
    b_r.push_back(b.at(i));
  }
  if (a_r > b_r) {
    cout << a_r << endl;
  } else {
    cout << b_r << endl;
  }
  return 0;
}