#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      v[i] = make_pair(x, y);
    }
    double first = 0;
    double second = 0;
    for (int i = 0; i < n - 1; i++) {
      first += v[i].first * v[i + 1].second;
      second += v[i].second * v[i + 1].first;
    }
    first += v[n - 1].first * v[0].second;
    second += v[n - 1].second * v[0].first;
    double res = 0.5 * (first - second);
    bool isCCW = true;
    if (res < 0) {
      res = -res;
      isCCW = false;
    }
    cout << (isCCW ? "CCW " : "CW ");
    cout << fixed << setprecision(1) << res << "\n";
  }
}