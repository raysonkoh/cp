#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double simulate(int k, int p, int a, int b, int c, int d) {
  return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int p, a, b, c, d, n;
  cin >> p >> a >> b >> c >> d >> n;

  double maxsofar = simulate(1, p, a, b, c, d);
  double best = 0;
  for (int i = 2; i <= n; i++) {
    double curr = simulate(i, p, a, b, c, d);
    best = max(best, maxsofar - curr);
    maxsofar = max(maxsofar, curr);
  }
  cout << fixed << setprecision(6) << best << endl;
}
