#include <iostream>
#include <map>
#include <set>
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
    vector<int> v(n);
    map<int, int> valToCount;
    map<int, set<int>> countToVal;
    int currIndx = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (currIndx == 0 || x != v[currIndx - 1]) {
        v[currIndx] = x;
        currIndx++;
        if (valToCount.find(x) == valToCount.end()) {
          valToCount[x] = 1;
          countToVal[1].insert(x);
        } else {
          countToVal[valToCount[x]].erase(x);
          valToCount[x]++;
          countToVal[valToCount[x]].insert(x);
        }
      } else {
        continue;
      }
    }

    int best = 1e9;
    for (auto p : countToVal) {
      int minOp = p.first + 1;
      for (auto x : p.second) {
        int tmp = minOp;
        if (v[0] == x) {
          tmp--;
        }
        if (v[currIndx - 1] == x) {
          tmp--;
        }
        best = min(best, tmp);
      }
    }
    cout << best << "\n";
  }
}