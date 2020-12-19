#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int g, s, c;
  cin >> g >> s >> c;
  int buyingpower = g * 3 + s * 2 + c;

  string bestvict = "", besttreasure = "Copper";
  if (buyingpower >= 8) {
    bestvict = "Province";
  } else if (buyingpower >= 5) {
    bestvict = "Duchy";
  } else if (buyingpower >= 2) {
    bestvict = "Estate";
  }

  if (buyingpower >= 6) {
    besttreasure = "Gold";
  } else if (buyingpower >= 3) {
    besttreasure = "Silver";
  } else if (buyingpower >= 0) {
    besttreasure = "Copper";
  }

  if (bestvict == "") {
    cout << besttreasure << endl;
  } else {
    cout << bestvict << " or " << besttreasure << endl;
  }
}