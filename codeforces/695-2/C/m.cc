#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;

  long long m1 = 0;
  long long min1 = 1e10;
  for (int i = 0; i < n1; i++) {
    long long x;
    cin >> x;
    m1 += x;
    min1 = min(min1, x);
  }

  long long m2 = 0;
  long long min2 = 1e10;
  for (int i = 0; i < n2; i++) {
    long long x;
    cin >> x;
    m2 += x;
    min2 = min(min2, x);
  }

  long long m3 = 0;
  long long min3 = 1e10;
  for (int i = 0; i < n3; i++) {
    long long x;
    cin >> x;
    m3 += x;
    min3 = min(min3, x);
  }

  vector<long long> v{min1, min2, min3};
  sort(v.begin(), v.end());

  long long opta = m1 + m2 + m3 - 2 * v[0] - 2 * v[1];      // take min from 2 diff bag to be odd dist from root
  long long optb = m1 + m2 + m3 - 2 * min(m1, min(m2, m3)); // take whole bag to be odd dist from root

  cout << max(opta, optb) << "\n";
}
