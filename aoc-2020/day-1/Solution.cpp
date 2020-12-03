#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n = 200;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  /*
  for (int i = 0; i < n; i++) {
    cout << v[i] << endl;
  }
  */
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == j || i == k || j == k) {
          continue;
        }

        if (v[i] + v[j] + v[k] == 2020) {
          cout << v[i] * v[j] * v[k] << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}