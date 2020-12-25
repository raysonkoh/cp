#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<long long> v1(n);
    for (int j = 0; j < n; j++) {
      cin >> v1[j];
    }
    vector<long long> v2(n);
    for (int j = 0; j < n; j++) {
      cin >> v2[j];
    }
    sort(v1.rbegin(), v1.rend());
    sort(v2.begin(), v2.end());

    long long res = 0;
    for (int j = 0; j < n; j++) {
      res += v1[j] * v2[j];
    }
    cout << "Case #" << i + 1 << ": " << res << endl;
  }
}