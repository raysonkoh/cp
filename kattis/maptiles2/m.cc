#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int numDigits = s.length();
  cout << numDigits << " ";

  int lox = 0;
  int hix = pow(2, numDigits) - 1;
  int loy = 0;
  int hiy = hix;

  int offset = (hix + 1) / 2;
  for (int i = 0; i < s.length(); i++) {
    int x = s.at(i) - '0';
    // cout << "x: " << x << endl;
    // cout << lox << " " << hix << endl;
    // cout << loy << " " << hiy << endl;
    if (x == 0) {
      // top left
      hix -= offset;
      hiy -= offset;
    } else if (x == 1) {
      // top right
      lox += offset;
      hiy -= offset;
    } else if (x == 2) {
      // bottom left
      hix -= offset;
      loy += offset;
    } else {
      // bottom right
      lox += offset;
      loy += offset;
    }
    offset /= 2;
  }
  cout << lox << " " << loy;

  cout << "\n";
}