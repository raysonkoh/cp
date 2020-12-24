#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n1, n2;
  cin >> n1 >> n2;

  int clockwise;
  if (n2 >= n1) {
    clockwise = n2 - n1;
  } else {
    clockwise = n2 + 360 - n1;
  }

  int anticlockwise;
  if (n2 <= n1) {
    anticlockwise = n1 - n2;
  } else {
    anticlockwise = n1 + 360 - n2;
  }
  if (clockwise == anticlockwise) {
    cout << clockwise << endl;
  } else if (clockwise > anticlockwise) {
    cout << anticlockwise * -1 << endl;
  } else {
    cout << clockwise << endl;
  }
}