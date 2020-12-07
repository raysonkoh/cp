#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    string res = "";
    for (int j = 0; j < a.length(); j++) {
      char ca = a.at(j);
      char cb = b.at(j);
      if (ca == cb) {
        res.push_back('.');
      } else {
        res.push_back('*');
      }
    }
    cout << a << endl << b << endl << res << endl << endl;
  }
  return 0;
}
