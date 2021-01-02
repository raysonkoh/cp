#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (m.find(x) == m.end()) {
        vector<int> tmp{i + 1};
        m[x] = tmp;
      } else {
        m[x].push_back(i + 1);
      }
    }
    bool isFound = false;
    for (auto p : m) {
      if (p.second.size() > 1) {
        continue;
      } else {
        isFound = true;
        cout << p.second[0] << "\n";
        break;
      }
    }
    if (!isFound) {
      cout << -1 << "\n";
    }
  }
}
