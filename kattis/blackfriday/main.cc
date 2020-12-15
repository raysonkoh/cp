#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  int outcomes[6];
  for (int i = 0; i < 6; i++) {
    outcomes[i] = 0;
  }
  map<int, int> m;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    outcomes[x - 1]++;
    m[x] = i + 1;
  }
  for (int i = 5; i >= 0; i--) {
    if (outcomes[i] == 1) {
      cout << m.find(i + 1)->second << endl;
      return 0;
    }
  }
  cout << "none" << endl;
}
