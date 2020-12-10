#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int res = m - n;
  if (res > 0) {
    if (res == 1) {
      cout << "Dr. Chaz will have " << res << " piece of chicken left over!"
           << endl;
    } else {
      cout << "Dr. Chaz will have " << res << " pieces of chicken left over!"
           << endl;
    }
  } else {
    res = abs(res);
    if (res == 1) {
      cout << "Dr. Chaz needs " << res << " more piece of chicken!" << endl;
    } else {
      cout << "Dr. Chaz needs " << res << " more pieces of chicken!" << endl;
    }
  }
  return 0;
}
