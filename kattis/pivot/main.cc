#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  vector<int> v;
  set<int> s;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  int res = 0;
  int currMax = v[0];
  s.insert(0);
  for (int i = 1; i < n; i++) {
    if (v[i] >= currMax) {
      currMax = v[i];
      // cout << "add " << v[i] << endl;
      s.insert(i);
    }
  }
  reverse(v.begin(), v.end());
  // for (int i = 0; i < n; i++) {
  //  cout << v[i] << " ";
  //}
  // cout << endl;

  int currMin = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] > currMin && s.find(n - 1 - i) != s.end()) {
      // cout << "earse: " << v[i] << endl;
      s.erase(n - 1 - i);
    }
    currMin = min(currMin, v[i]);
  }
  cout << s.size() << endl;
}