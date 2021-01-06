#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool checkAP(vector<int> &v) {
  int currDiff = -1;
  for (int i = 0; i < v.size(); i++) {
    if (i == 0) {
      continue;
    } else if (i == 1) {
      currDiff = v[i] - v[i - 1];
    } else if (v[i] - v[i - 1] != currDiff) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
    }

    if (checkAP(v))
      cout << "arithmetic\n";
    else {
      sort(v.begin(), v.end());
      if (checkAP(v)) {
        cout << "permuted arithmetic\n";
      } else {
        cout << "non-arithmetic\n";
      }
    }
  }
}