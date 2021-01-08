#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int s = 0;
  vector<int> v(9);
  for (int i = 0; i < v.size(); i++) {
    cin >> v[i];
    s += v[i];
  }
  int target = s - 100;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] + v[j] == target) {
        for (int k = 0; k < v.size(); k++) {
          if (k != i && k != j) {
            cout << v[k] << "\n";
          }
        }
        return 0;
      }
    }
  }
}