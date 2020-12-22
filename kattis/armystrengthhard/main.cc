#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int ng, nm;
    cin >> ng >> nm;
    int maxng = -1;
    int maxnm = -1;
    for (int j = 0; j < ng; j++) {
      int x;
      cin >> x;
      maxng = max(maxng, x);
    }
    for (int j = 0; j < nm; j++) {
      int x;
      cin >> x;
      maxnm = max(maxnm, x);
    }
    if (maxng == maxnm) {
      cout << "Godzilla" << endl;
    } else if (maxng > maxnm) {
      cout << "Godzilla" << endl;
    } else {
      cout << "MechaGodzilla" << endl;
    }
  }
}