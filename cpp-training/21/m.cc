#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> v(2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 10; j++) {
      v[i].push_back(j);
    }
  }
  for (auto x : v) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << '\n';
  }
}