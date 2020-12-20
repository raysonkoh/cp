#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<bool> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  while (cin >> n) {
    vector<bool> v(n - 1, false);
    int prev = -1;
    for (int i = 0; i < n; i++) {

      int x;
      cin >> x;
      if (i == 0) {
        prev = x;
      } else {
        int diff = abs(x - prev) - 1;
        if (diff >= 0 && diff <= n - 2) {
          v[diff] = true;
        }
        prev = x;
      }
    }

    // print(v);
    if (n == 1) {
      cout << "Jolly" << endl;
    } else {
      bool isJolly = true;
      for (int i = 0; i < v.size(); i++) {
        if (!v[i]) {
          cout << "Not jolly" << endl;
          isJolly = false;
          break;
        }
      }
      if (isJolly) {
        cout << "Jolly" << endl;
      }
    }
  }
}