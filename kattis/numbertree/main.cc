#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int h;
  string s;
  cin >> h >> s;
  int maxNum = pow(2, h + 1) - 1;
  int curr = maxNum;
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    if (c == 'L') {
      curr = (curr << 1) & maxNum;
    } else {
      curr = ((curr << 1) & maxNum) - 1;
    }
  }
  cout << curr << endl;
}