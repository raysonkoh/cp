#include <iostream>

using namespace std;

int main() {
  int n = 1000;
  int res = 0;
  for (int i = 0; i < n; i++) {
    string first, second, third;
    cin >> first >> second >> third;
    int a, b;
    string tmp = "";

    for (int i = 0; i < first.length(); i++) {
      char c = first.at(i);
      if (c == '-') {
        a = stoi(tmp);
        tmp = "";
      } else {
        tmp.push_back(c);
      }
    }
    b = stoi(tmp);

    char ch = second.at(0);

    if (third.at(a - 1) == ch ^ third.at(b - 1) == ch) {
      // cout << third << endl;
      res++;
    }

    /* Part 1
    int counter = 0;
    for (int i = 0; i < third.length(); i++) {
      char c = third.at(i);
      if (c == ch) {
        counter++;
      }
    }

    if (!(counter < a || counter > b)) {
      // cout << i << endl;
      res++;
    }
    */

    /*
    cout << a << " " << b << endl;
    cout << ch << endl;
    cout << third << endl;
    */
  }
  cout << res << endl;
  return 0;
}