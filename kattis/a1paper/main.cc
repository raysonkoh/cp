#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<double> &v) {
  for (int x : v) {
    cout << x << ' ';
  }
  cout << endl;
}

int getLong(int x) { return 3 + x * 2; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<double> v(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> v[i];
  }
  double res = 0;
  vector<double> needs(n - 1);

  needs[0] = 2 - v[0];

  for (int i = 1; i < n - 1; i++) {
    res += needs[i - 1] * pow(2, -1 * (getLong(i) / 4.0));
    needs[i] = 2 * needs[i - 1] - v[i];
    if (needs[i] <= 0) {
      break;
    }
  }

  if (needs[n - 2] > 0) {
    cout << "impossible\n";
  } else {
    res += pow(2, -1 * (getLong(0) / 4.0));
    cout << fixed << setprecision(8) << res << endl;
  }
}