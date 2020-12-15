#include <iostream>

using namespace std;

int main() {
  int sweet, sour;
  while (cin >> sweet >> sour) {
    if (sweet == 0 && sour == 0) {
      break;
    }
    if (sweet + sour == 13) {
      cout << "Never speak again." << endl;
    } else if (sour > sweet) {
      cout << "Left beehind." << endl;
    } else if (sweet > sour) {
      cout << "To the convention." << endl;
    } else if (sweet == sour) {
      cout << "Undecided." << endl;
    }
  }
}
