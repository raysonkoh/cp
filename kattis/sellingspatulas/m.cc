#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define P 1000000007
#define EPS 1e-3

using namespace std;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);
  cout << fixed << setprecision(2);
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    vector<pair<int, double>> v(n); // (time, prof)
    for (int i = 0; i < n; i++) {
      int m;
      double x;
      cin >> m >> x;
      v[i] = {m, x};
    }

    sort(v.begin(), v.end());

    bool init = true;
    double best;
    int bestStart, bestLen;
    for (int i = 0; i < n; i++) {
      double curr = 0.0;
      int s = v[i].first;
      for (int j = i; j < n; j++) {
        curr += v[j].second;
        double tmp = curr - (v[j].first - s + 1) * (0.08);
        int d = j - i + 1;
        if (init) {
          init = false;
          best = tmp;
          bestStart = i;
          bestLen = d;
        } else if (fabs(tmp - best) <= EPS) {
          if (d < bestLen || (d == bestLen && i < bestStart)) {
            bestStart = i;
            bestLen = d;
          }
        } else if (tmp > best + EPS) {
          best = tmp;
          bestStart = i;
          bestLen = d;
        }
      }
    }

    if (init || best <= 0) {
      cout << "no profit\n";
      // printf("no profit\n");
    } else {
      // printf("%.2f %d %d\n", best, v[bestStart].first, v[bestStart + bestLen - 1].first);
      cout << best << " " << v[bestStart].first << " " << v[(bestStart + bestLen - 1)].first << "\n";
    }
  }
}
