#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    v[i] = c;
  }
  sort(v.rbegin(), v.rend());
  long res = 0;
  int lastConsidered = -1;
  for (int i = 0; i < v.size(); i += 3) {
    int a = v[i];
    int b = v[i + 1];
    int c = v[i + 2];
    res += a + b;
    lastConsidered = i + 2;
  }
  for (int i = lastConsidered + 1; i < v.size(); i++) {
    res += v[i];
  }
  cout << res << endl;
  return 0;
}