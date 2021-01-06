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
  int tol = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    tol += v[i];
  }
  sort(v.rbegin(), v.rend());
  int alice = 0;
  for (int i = 0; i < n; i += 2) {
    alice += v[i];
  }
  cout << alice << " " << tol - alice << '\n';
}