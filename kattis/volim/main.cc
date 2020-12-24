#include <iostream>

using namespace std;

int getNextPerson(int x) {
  if (x == 8) {
    return 1;
  }
  return x + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int k, n;
  cin >> k >> n;

  int currTime = 0;
  int player = k;

  for (int i = 0; i < n; i++) {
    int t;
    char c;
    cin >> t >> c;
    if (currTime + t >= 210) {
      cout << player << endl;
      return 0;
    }
    currTime += t;
    if (c == 'T') {
      player = getNextPerson(player);
    }
  }
}