#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  int res = -1;
  int offset = 1;
  for (int i = v.size() - 1; i >= 0; i--) {
    res = max(res, v[i] + offset);
    offset++;
  }
  cout << res + 1 << endl;
  return 0;
}