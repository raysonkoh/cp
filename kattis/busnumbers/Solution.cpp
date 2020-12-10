#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> v = vector<bool>(1000);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    v[x] = 1;
  }

  int lo = -1;
  int hi = -1;
  bool firstPrint = true;
  for (int i = 0; i < 1000; i++) {

    if (lo == -1 && v[i] == 1) {
      lo = i;
      hi = i;
    } else if (lo != -1 && v[i] == 1) {
      hi = i;
    } else if (lo != -1 && v[i] != 1) {
      if (firstPrint) {
        firstPrint = false;
      } else {
        cout << " ";
      }
      if (lo == hi) {
        cout << lo + 1;
      } else if (lo == hi - 1) {
        cout << lo + 1 << " " << hi + 1;
      } else {
        cout << lo + 1 << "-" << hi + 1;
      }

      lo = -1;
      hi = -1;
    }
  }

  if (lo != -1) {
    cout << " ";
    if (lo == hi) {
      cout << lo + 1;
    } else if (lo == hi - 1) {
      cout << lo + 1 << " " << hi + 1;
    } else {
      cout << lo + 1 << "-" << hi + 1;
    }
  }

  cout << endl;
  return 0;
}