#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  long long res = 0;
  for (int i = 0; i < n; i += 3) {
    if (i + 2 < n) {
      res += v[i + 2];
    }
  }
  cout << res << endl;
}